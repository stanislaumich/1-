spool create_user.log
shutdown immediate;
startup restrict;
--ALTER DATABASE CHARACTER SET INTERNAL_USE CL8MSWIN1251;
ALTER DATABASE CHARACTER SET INTERNAL_USE AL32UTF8;
shutdown immediate;
startup;
drop user firma cascade;
create user firma identified by firma default tablespace users temporary tablespace temp;
grant dba to firma;
grant create session to firma;
spool off
exit;