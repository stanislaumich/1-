/* Formatted on 01/06/2021 23:48:24 (QP5 v5.360) */
-- a Кто из владельцев счетов данного банка имеет кредиты на  данную дату

SELECT name n, data d, summa s
  FROM schet s, firma9 f
 WHERE f.idschet = s.id AND s.data >= '13/07/2006' AND s.credit = 'Y'
UNION
SELECT name n, data d, summa s
  FROM schet s, postav f
 WHERE f.idschet = s.id AND s.data >= '13/07/2006' AND s.credit = 'Y'
UNION
SELECT fio n, data d, summa s
  FROM schet s, client f
 WHERE f.idschet = s.id AND s.data >= '13/07/2006' AND s.credit = 'Y'
--
--
-- b Определить юридический адрес и номера телефонов данной фирмы


SELECT uradr, phone FROM firma9

--
-- c Кто из сотрудников данной фирмы был принят на работу на данную дату

/* Formatted on 01/06/2021 23:48:30 (QP5 v5.360) */
SELECT *
  FROM sotrud
 WHERE data = '21/07/2018'

--
-- d Кто из поставщиков имеет кредит на сумму превышающую заданную?

/* Formatted on 01/06/2021 23:50:50 (QP5 v5.360) */
SELECT p.name, s.summa
  FROM postav p, schet s
 WHERE s.id = p.idschet AND s.Credit = 'Y' AND s.summa > 379
 
 
 --
 -- e Найти юридические адреса клиентов, которые оформили заказы на данную дату
 
/* Formatted on 01/06/2021 23:54:15 (QP5 v5.360) */
SELECT c.fio, c.adr
  FROM client c, zakaz z
 WHERE z.idclient = c.id AND z.data = '02/11/2020'