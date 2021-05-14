chcp 1251
md s:\MYSQL_BACKUP
del backupPREV.dmp
ren s:\MYSQL_BACKUP\backup.dmp backupPREV.dmp
C:\MYSQL\BIN\MYSQLDUMP -u root -h localhost -pRoot12Root firma9 > s:\MYSQL_BACKUP\backup.dmp

rar a -m5 -ag_dd.mm.yyyy-hh-mi-ss backup @backup.lst
rem pause
rem rar a -sfx -ag_dd.mm.yyyy-hh-mi-ss oplata_backup D:\CLOUD\Dropbox\common(THS)\oplata.exe
rem del D:\CLOUD\Dropbox\common(THS)\oplata.exe
copy *.rar "s:\ONE DRIVE\OneDrive - heds\Контрольные\УНИВЕР\1 курс\1й курс летняя сессия\БД\backup"
del *.rar

pause