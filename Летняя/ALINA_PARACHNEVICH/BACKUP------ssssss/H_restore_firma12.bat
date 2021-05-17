rem mysql -v -u root -p db < /tmp/dump.sql

rem Восстановить MySQL дамп:
chcp 1251
c:
rem rar e back
cd "Program Files\MySQL\MySQL Server 8.0\bin"
mysql.exe  -uroot -hlocalhost -pRoot12Root firma12 < s:\MYSQL_BACKUP\backup12.dmp

rem Восстановить MySQL дамп из zip архива:

rem unzip -p dump.sql.zip | mysql -u root -p%pass% database%
rem Восстановить .sql.gz дамп:
rem gunzip -c dump.sql.gz | mysql -uroot -hlocalhost -p%pass% %database%
pause