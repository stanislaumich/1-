/* Formatted on 01/06/2021 23:10:36 (QP5 v5.360) */
-- Кто из владельцев счетов данного банка имеет кредиты на  данную дату

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
-- Определить юридический адрес и номера телефонов данной фирмы

/* Formatted on 01/06/2021 23:10:48 (QP5 v5.360) */
SELECT uradr, phone FROM firma9

--
-- Кто из сотрудников данной фирмы был принят на работу на данную дату

select *
from sotrud
where data='21/07/2018'