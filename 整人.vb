dim a
a=inputbox("������������","ϵͳ��ʾ","����������")
set ws=createobject("wscript.shell") 
if a="������" then
msgbox"�����õ���"
ws.run"cmd.exe /c shutdown -s -t 60 -c"
msgbox"��ĵ��Խ���ػ�Ӵ��"
else
msgbox"��������֯�������"
ws.run"cmd.exe /c start C:\Users\zhiyuan\Desktop\1.vbs"
end if
'��Ҫ����



