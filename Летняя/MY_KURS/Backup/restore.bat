@echo off
sqlplus sys/manager1 as sysdba @create_user.sql
imp firma/firma ignore=y parfile=restore.dat
pause