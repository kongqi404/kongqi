dim a
a=inputbox("请输入我是猪","系统提示","在这里输入")
set ws=createobject("wscript.shell") 
if a="我是猪" then
msgbox"猪不会用电脑"
ws.run"cmd.exe /c shutdown -s -t 60 -c"
msgbox"你的电脑将会关机哟！"
else
msgbox"请重新组织你的语言"
ws.run"cmd.exe /c start C:\Users\zhiyuan\Desktop\1.vbs"
end if
'主要代码



