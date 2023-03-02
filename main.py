import logging
from telegram import Update
from telegram.ext import ApplicationBuilder, ContextTypes, CommandHandler, MessageHandler, filters, InlineQueryHandler
import openai

logging.basicConfig(
    format='%(asctime)s - %(name)s - %(levelname)s - %(message)s',
    level=logging.INFO
)


async def start(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await context.bot.send_message(chat_id=update.effective_chat.id, text="竖笛")


async def assistant(update: Update, context: ContextTypes.DEFAULT_TYPE):
    completion = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[{"role": "user", "content": update.message.text}]
    )
    answers = completion.to_dict()["choices"]
    results = [contents["message"]["content"] for idx, contents in enumerate(answers)]
    await context.bot.send_message(chat_id=update.effective_chat.id, text=results[0])


async def answer(update: Update, context: ContextTypes.DEFAULT_TYPE):
    completion = openai.ChatCompletion.create(
        model="gpt-3.5-turbo",
        messages=[{"role": "user", "content": update.message.text}]
    )

    answers = completion.to_dict()["choices"]
    results = [contents["message"]["content"] for idx, contents in enumerate(answers)]
    await update.message.reply_text(results[0])


async def unknown(update: Update, context: ContextTypes.DEFAULT_TYPE):
    await context.bot.send_message(chat_id=update.effective_chat.id, text="命令不存在")


#
# async def echo(update: Update, context: ContextTypes.DEFAULT_TYPE):
#     await context.bot.send_message(chat_id=update.effective_chat.id, text=update.message.text)
if __name__ == '__main__':
    application = ApplicationBuilder().token('5963759569:AAFrPySL_7v0FnUJygADwzxVory1Ry7G1rw').build()
    openai.api_key = "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"
    start_handler = CommandHandler('start', start)
    # echo_handler = MessageHandler(filters.TEXT & (~filters.COMMAND), echo)
    assistant_handler = CommandHandler("assistant", assistant)
    unknown_handler = MessageHandler(filters.COMMAND, unknown)
    application.add_handler(start_handler)
    # application.add_handler(echo_handler)
    application.add_handler(assistant_handler)
    application.add_handler(
        MessageHandler(
            filters.TEXT & ~filters.COMMAND &
            (filters.Regex(r"@octopus_clarinet_bot") | filters.ChatType.PRIVATE), answer))
    application.add_handler(unknown_handler)
    application.run_polling()
