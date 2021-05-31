rem mysql -v -u root -p db < /tmp/dump.sql

rem Восстановить MySQL дамп:

mysql -uroot -hlocalhost -pKurs12Kurs firma9 < /backup.dmp

rem Восстановить MySQL дамп из zip архива:

rem unzip -p dump.sql.zip | mysql -u root -p%pass% database%
rem Восстановить .sql.gz дамп:
rem gunzip -c dump.sql.gz | mysql -uroot -hlocalhost -p%pass% %database%