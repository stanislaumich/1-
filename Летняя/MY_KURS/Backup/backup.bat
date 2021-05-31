rem @echo off
del backup_prev.dmp
ren backup.dmp backup_prev.dmp
del backup.dmp
sqlplus firma/firma @backup.sql
exp firma/firma parfile=backup.dat
del *.log
rar a -m5 -ag_dd.mm.yyyy-hh-mi-ss backup @backup.lst
rem pause
