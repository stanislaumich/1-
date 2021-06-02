-- --------------------------------------------------------
-- Хост:                         127.0.0.1
-- Версия сервера:               8.0.25 - MySQL Community Server - GPL
-- Операционная система:         Win64
-- HeidiSQL Версия:              11.2.0.6213
-- --------------------------------------------------------

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET NAMES utf8 */;
/*!50503 SET NAMES utf8mb4 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;


-- Дамп структуры базы данных dmaslak
DROP DATABASE IF EXISTS `dmaslak`;
CREATE DATABASE IF NOT EXISTS `dmaslak` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `dmaslak`;

-- Дамп структуры для таблица dmaslak.firma
DROP TABLE IF EXISTS `firma`;
CREATE TABLE IF NOT EXISTS `firma` (
  `firma` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT '',
  `telefon` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT '',
  `schet` int NOT NULL,
  `id` int NOT NULL AUTO_INCREMENT,
  PRIMARY KEY (`id`),
  KEY `FKschetf` (`schet`) USING BTREE,
  CONSTRAINT `FKschetf` FOREIGN KEY (`schet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Описание фирмы';

-- Дамп данных таблицы dmaslak.firma: ~1 rows (приблизительно)
DELETE FROM `firma`;
/*!40000 ALTER TABLE `firma` DISABLE KEYS */;
INSERT INTO `firma` (`firma`, `uradr`, `telefon`, `schet`, `id`) VALUES
	('com40', 'PODKOCKA 4B, 63-460 NOWE SKALMIERZYCE', '62 76 29 550', 4, 0);
/*!40000 ALTER TABLE `firma` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.izgot
DROP TABLE IF EXISTS `izgot`;
CREATE TABLE IF NOT EXISTS `izgot` (
  `n` int NOT NULL AUTO_INCREMENT,
  `name` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`n`),
  UNIQUE KEY `name` (`name`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.izgot: ~3 rows (приблизительно)
DELETE FROM `izgot`;
/*!40000 ALTER TABLE `izgot` DISABLE KEYS */;
INSERT INTO `izgot` (`n`, `name`) VALUES
	(1, 'ОАО "Бабушкина крынка"'),
	(2, 'ООО "АМКОР"'),
	(3, 'ЧПТУП "ИНФОЦЕНТР"');
/*!40000 ALTER TABLE `izgot` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.kadry
DROP TABLE IF EXISTS `kadry`;
CREATE TABLE IF NOT EXISTS `kadry` (
  `N` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) NOT NULL,
  `dolg` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `obraz` enum('Высшее','Среднеспециальное','Среднее','Базовое') NOT NULL,
  `salary` float(12,0) unsigned NOT NULL,
  `data` date NOT NULL,
  `firma` int NOT NULL,
  PRIMARY KEY (`N`) USING BTREE,
  UNIQUE KEY `i2` (`fio`),
  UNIQUE KEY `idkadr` (`N`) USING BTREE,
  UNIQUE KEY `fio` (`fio`),
  KEY `FK_kadry_firma` (`firma`),
  CONSTRAINT `FK_kadry_firma` FOREIGN KEY (`firma`) REFERENCES `firma` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Сотрудники фирмы';

-- Дамп данных таблицы dmaslak.kadry: ~8 rows (приблизительно)
DELETE FROM `kadry`;
/*!40000 ALTER TABLE `kadry` DISABLE KEYS */;
INSERT INTO `kadry` (`N`, `fio`, `dolg`, `obraz`, `salary`, `data`, `firma`) VALUES
	(1, 'Анатолий Николаевич Жерносенко', 'Генеральный директор (приемная)', 'Базовое', 1500, '2014-08-21', 0),
	(2, 'Юрий Владимирович Главатский', 'Главный инженер', 'Высшее', 1450, '2014-08-21', 0),
	(3, 'Андрей Николаевич Рожков', 'Зам. генерального директора по кадровой, идеологической работе и экономической безопасности', 'Высшее', 1350, '2014-08-22', 0),
	(4, 'Сергей Борисович Юзвяк', 'Зам. генерального директора по материально-техническому снабжению и транспорту', 'Высшее', 1355, '2014-08-21', 0),
	(5, 'Андрей Владимирович Пескун', 'Зам. генерального директора – начальник управления маркетинга, сбыта и фирменного обслуживания', 'Высшее', 1400, '2014-08-21', 0),
	(6, 'Александр Николаевич Таланцев', 'Главный бухгалтер', 'Высшее', 1000, '2014-08-24', 0),
	(7, 'Ольга Михайловна Старченко', 'Начальник ОТК', 'Среднеспециальное', 1000, '2014-08-25', 0),
	(8, 'Елена Адамовна Рапеева', 'Главный технолог', 'Высшее', 1100, '2014-08-21', 0);
/*!40000 ALTER TABLE `kadry` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.klient
DROP TABLE IF EXISTS `klient`;
CREATE TABLE IF NOT EXISTS `klient` (
  `n` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `adres` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT NULL,
  `schet` int DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `i3` (`fio`),
  UNIQUE KEY `idclient` (`n`) USING BTREE,
  UNIQUE KEY `fio` (`fio`),
  KEY `FKschet` (`schet`) USING BTREE,
  CONSTRAINT `FKschet` FOREIGN KEY (`schet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.klient: ~10 rows (приблизительно)
DELETE FROM `klient`;
/*!40000 ALTER TABLE `klient` DISABLE KEYS */;
INSERT INTO `klient` (`n`, `fio`, `adres`, `schet`) VALUES
	(1, 'Жукова Алиса Олеговна', 'г. Забарье, ул. Ольховская 2-я, дом 71', 14),
	(2, 'Кольцов Максим Иванович', 'г. Шацк, ул. Кучин пер, дом 110', 11),
	(3, 'Мальцев Даниил Романович', 'г. Родино, ул. Вавиловых, дом 142', 13),
	(4, 'Мешкова Василиса Владиславовна', 'г. Мантурово, ул. Новоясеневский пр-кт, дом 113', 19),
	(5, 'Нефедов Максим Тимурович', 'г. Полтавское, ул. Моцарта, дом 193', 12),
	(6, 'Смирнов Матвей Алексеевич', 'г. Жилино, ул. Бойцова пер, дом 118', 15),
	(7, 'Софронова Мария Марковна', 'г. Туринск, ул. Новолужнецкий проезд, дом 12', 17),
	(8, 'Субботина Мария Никитична', 'г. Курагино, ул. Талалихина пер, дом 180', 16),
	(9, 'Сухов Матвей Алексеевич', ' г. Верхняя Хава, ул. Лукино 2-я, дом 174', 20),
	(10, 'Яковлева Варвара Николаевна', 'г. Холмогорье, ул. Рассветная, дом 197', 18);
/*!40000 ALTER TABLE `klient` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.nakladnaya
DROP TABLE IF EXISTS `nakladnaya`;
CREATE TABLE IF NOT EXISTS `nakladnaya` (
  `n` int NOT NULL AUTO_INCREMENT,
  `ntovar` int NOT NULL,
  `kolvo` int unsigned NOT NULL,
  `summa` float(12,0) unsigned NOT NULL,
  `nklient` int NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idnaklad` (`n`) USING BTREE,
  KEY `FKtovarn` (`ntovar`) USING BTREE,
  KEY `FK_nakladnaya_klient` (`nklient`) USING BTREE,
  CONSTRAINT `FK_nakladnaya_klient` FOREIGN KEY (`nklient`) REFERENCES `klient` (`n`),
  CONSTRAINT `FKtovarn` FOREIGN KEY (`ntovar`) REFERENCES `tovar` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Накладные на товар';

-- Дамп данных таблицы dmaslak.nakladnaya: ~5 rows (приблизительно)
DELETE FROM `nakladnaya`;
/*!40000 ALTER TABLE `nakladnaya` DISABLE KEYS */;
INSERT INTO `nakladnaya` (`n`, `ntovar`, `kolvo`, `summa`, `nklient`) VALUES
	(1, 1, 3, 60, 1),
	(2, 2, 5, 100, 2),
	(3, 6, 1, 55, 6),
	(4, 7, 1, 20, 4),
	(5, 10, 5, 55, 7);
/*!40000 ALTER TABLE `nakladnaya` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.postav
DROP TABLE IF EXISTS `postav`;
CREATE TABLE IF NOT EXISTS `postav` (
  `n` int NOT NULL AUTO_INCREMENT,
  `nazv` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `schet` int DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idpostav` (`n`) USING BTREE,
  UNIQUE KEY `i4` (`nazv`) USING BTREE,
  UNIQUE KEY `nazv` (`nazv`),
  KEY `FKschetp` (`schet`) USING BTREE,
  CONSTRAINT `FKschetp` FOREIGN KEY (`schet`) REFERENCES `schet` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Поставщики';

-- Дамп данных таблицы dmaslak.postav: ~10 rows (приблизительно)
DELETE FROM `postav`;
/*!40000 ALTER TABLE `postav` DISABLE KEYS */;
INSERT INTO `postav` (`n`, `nazv`, `uradr`, `schet`) VALUES
	(1, 'Siedziba firmy Personio', 'Strażacka 41A/64, 84-331 Piaseczno', 4),
	(2, 'Dom w Konstancinie', 'Wczasowa 07A, 35-983 Pawłowice', 3),
	(3, 'L\'Oreal House Warsaw', 'Równa 31, 65-189 Płock', 5),
	(4, 'Microsoft Polska', 'Miła 09/65, 70-122 Koszalin', 1),
	(5, 'Hotel Provita', 'Zbożowa 33, 06-300 Ełk', 2),
	(6, 'Hotel Marriott', 'Bielska 40/80, 37-406 Żywiec', 7),
	(7, 'NH Hotel Bloom', 'Kołobrzeska 64/48, 14-495 Tomaszów Mazowiecki', 8),
	(8, 'Penthaus', 'Sienkiewicza Henryka 06/92, 40-829', 10),
	(9, 'Novotel', 'Puławska 38/94, 29-547 Rybnik', 6),
	(10, 'Sofitel', 'Srebrna 97/23, 50-973 Legnica', 9);
/*!40000 ALTER TABLE `postav` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.schet
DROP TABLE IF EXISTS `schet`;
CREATE TABLE IF NOT EXISTS `schet` (
  `n` int NOT NULL AUTO_INCREMENT,
  `bank` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `numb` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `sost` int NOT NULL DEFAULT '0',
  `data` date NOT NULL,
  `cr` enum('Y','N') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `summa` float(12,0) unsigned DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idschet` (`n`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=21 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.schet: ~20 rows (приблизительно)
DELETE FROM `schet`;
/*!40000 ALTER TABLE `schet` DISABLE KEYS */;
INSERT INTO `schet` (`n`, `bank`, `numb`, `sost`, `data`, `cr`, `summa`) VALUES
	(1, 'PKO Bank Polski', '251485758', 820, '2015-01-08', 'N', 35419),
	(2, 'Bank Pekao SA', '251452854', 366, '2015-06-12', 'Y', 42386),
	(3, 'Santander Bank Polska', '956256325', 540, '2015-06-17', 'N', 42170),
	(4, 'MBank', '254152889', 5673, '2016-08-18', 'N', 30382),
	(5, 'ING Bank Śląski', '325856984', 7655, '2017-07-26', 'N', 92809),
	(6, 'Bank Millennium', '233625990', 359, '2014-06-12', 'Y', 64122),
	(7, 'Bank BNP Paribas', '000025215', 5513, '2015-11-18', 'Y', 67116),
	(8, 'Alior Bank', '985578067', 244, '2016-06-06', 'Y', 60970),
	(9, 'Getin Noble Bank', '641923519', 574, '2019-01-04', 'N', 94065),
	(10, 'Raiffeisen Bank International', '412455125', 783, '2017-05-01', 'N', 94812),
	(11, 'Citi Handlowy', '214758941', 532, '2020-06-30', 'Y', 88921),
	(12, 'Idea Bank', '124789812', 89, '2016-11-07', 'N', 50243),
	(13, 'Bank BPS', '709123487', 264, '2017-08-03', 'Y', 1143),
	(14, 'Credit Agricole', '908746123', 90, '2017-08-18', 'N', 10787),
	(15, 'BOŚ Bank', '679854334', 783, '2018-03-16', 'N', 4184),
	(16, 'SGB Bank', '563354363', 717, '2018-08-22', 'N', 32623),
	(17, 'Santander Consumer Bank', '439875354', 300, '2018-10-01', 'Y', 13272),
	(18, 'Bank Pocztowy', '809645352', 456, '2019-12-24', 'Y', 10787),
	(19, 'Nest Bank', '894213567', 1290, '2020-07-30', 'N', 9149),
	(20, 'Volkswagen Bank Polska', '765433653', 200, '2021-01-15', 'Y', 777777);
/*!40000 ALTER TABLE `schet` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.sklad
DROP TABLE IF EXISTS `sklad`;
CREATE TABLE IF NOT EXISTS `sklad` (
  `N` int unsigned NOT NULL AUTO_INCREMENT,
  `adres` varchar(5000) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`N`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.sklad: ~10 rows (приблизительно)
DELETE FROM `sklad`;
/*!40000 ALTER TABLE `sklad` DISABLE KEYS */;
INSERT INTO `sklad` (`N`, `adres`) VALUES
	(1, 'Częstochowska 39A, 88-986 Skierniewice'),
	(2, 'Wolności Pl. 78, 65-200 Elbląg'),
	(3, 'Spółdzielcza 06A/35, 41-304 Bolesławiec'),
	(4, 'Górnośląska 07, 83-899 Tomaszów Mazowiecki'),
	(5, 'Wojska Polskiego 98/17, 67-976 Wągrowiec'),
	(6, 'Żołnierska 13A, 63-426 Oświęcim'),
	(7, 'Pawia 53A/53, 95-501 Oświęcim'),
	(8, 'Hallera Józefa 35A/64, 95-390 Kozienice'),
	(9, 'Młynarska 92, 46-445 Radom'),
	(10, 'Wspólna 33, 84-324 Konstancin-Jeziorna');
/*!40000 ALTER TABLE `sklad` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.tovar
DROP TABLE IF EXISTS `tovar`;
CREATE TABLE IF NOT EXISTS `tovar` (
  `n` int NOT NULL AUTO_INCREMENT,
  `name` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `ed` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `cena` int unsigned NOT NULL,
  `postav` int NOT NULL,
  `sklad` int unsigned NOT NULL,
  `Kolvo` int unsigned NOT NULL,
  `sort` int unsigned NOT NULL,
  `izgot` int DEFAULT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `idtovar` (`n`) USING BTREE,
  KEY `i5` (`name`) USING BTREE,
  KEY `FKpostavt` (`postav`) USING BTREE,
  KEY `FK_tovar_sklad` (`sklad`) USING BTREE,
  KEY `FK_tovar_izgot` (`izgot`),
  FULLTEXT KEY `name` (`name`),
  CONSTRAINT `FK_tovar_izgot` FOREIGN KEY (`izgot`) REFERENCES `izgot` (`n`),
  CONSTRAINT `FK_tovar_sklad` FOREIGN KEY (`sklad`) REFERENCES `sklad` (`N`),
  CONSTRAINT `FKpostavt` FOREIGN KEY (`postav`) REFERENCES `postav` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=11 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список товаров нормализованный';

-- Дамп данных таблицы dmaslak.tovar: ~10 rows (приблизительно)
DELETE FROM `tovar`;
/*!40000 ALTER TABLE `tovar` DISABLE KEYS */;
INSERT INTO `tovar` (`n`, `name`, `ed`, `cena`, `postav`, `sklad`, `Kolvo`, `sort`, `izgot`) VALUES
	(1, 'Диваны', 'шт', 1500, 1, 9, 989, 1, 1),
	(2, 'Диваны раскладные', 'шт', 3000, 2, 7, 356, 0, 2),
	(3, 'Пуфы', 'шт', 250, 1, 10, 916, 2, 3),
	(4, 'Кресла', 'шт', 500, 2, 8, 800, 1, 3),
	(5, 'Подножки', 'шт', 100, 1, 4, 80, 3, 2),
	(6, 'Стулья', 'шт', 50, 4, 3, 713, 2, 1),
	(7, 'Книжный шкаф', 'шт', 350, 6, 4, 659, 7, 2),
	(8, 'Лампы', 'шт', 20, 7, 9, 322, 2, 3),
	(9, 'Кровать', 'шт', 2350, 4, 7, 740, 1, 2),
	(10, 'Столы', 'шт', 450, 6, 3, 999, 3, 1);
/*!40000 ALTER TABLE `tovar` ENABLE KEYS */;

-- Дамп структуры для таблица dmaslak.transport
DROP TABLE IF EXISTS `transport`;
CREATE TABLE IF NOT EXISTS `transport` (
  `n` int NOT NULL AUTO_INCREMENT,
  `nomer` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `marka` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `gruz` float(12,0) NOT NULL,
  `god` int NOT NULL,
  `fio` varchar(150) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `data` date NOT NULL,
  `sklad` int unsigned NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `i5` (`nomer`),
  KEY `FK_transport_sklad` (`sklad`) USING BTREE,
  CONSTRAINT `FK_transport_sklad` FOREIGN KEY (`sklad`) REFERENCES `sklad` (`N`)
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы dmaslak.transport: ~6 rows (приблизительно)
DELETE FROM `transport`;
/*!40000 ALTER TABLE `transport` DISABLE KEYS */;
INSERT INTO `transport` (`n`, `nomer`, `marka`, `gruz`, `god`, `fio`, `data`, `sklad`) VALUES
	(2, 'Х 410 Х А', 'MD-11', 340000, 2010, 'Com-Avia', '2014-09-24', 3),
	(3, 'В 189 У К', 'SCANIA', 70000, 2011, 'Com-Avto', '2014-10-10', 4),
	(4, 'С 159 Н У', 'MAЗ', 24000, 2014, 'Com-Avto', '2014-11-27', 1),
	(5, 'Р 115 С О', 'RENAULT', 3400, 2012, 'Com-Avto', '2014-08-28', 3),
	(6, 'В 674 К Т', 'FOTON', 50000, 2012, 'Com-Avto', '2014-09-24', 5),
	(7, 'Х 360 О Е', 'Ан-225', 520000, 2013, 'Com-Avia', '2015-01-07', 10);
/*!40000 ALTER TABLE `transport` ENABLE KEYS */;

-- Дамп структуры для представление dmaslak.viewa
DROP VIEW IF EXISTS `viewa`;
-- Создание временной таблицы для обработки ошибок зависимостей представлений


-- Дамп структуры для представление dmaslak.viewb
DROP VIEW IF EXISTS `viewb`;
-- Создание временной таблицы для обработки ошибок зависимостей представлений


-- Дамп структуры для представление dmaslak.viewc
DROP VIEW IF EXISTS `viewc`;
-- Создание временной таблицы для обработки ошибок зависимостей представлений


-- Дамп структуры для представление dmaslak.viewd
DROP VIEW IF EXISTS `viewd`;
-- Создание временной таблицы для обработки ошибок зависимостей представлений


-- Дамп структуры для представление dmaslak.viewe
DROP VIEW IF EXISTS `viewe`;
-- Создание временной таблицы для обработки ошибок зависимостей представлений


-- Дамп структуры для таблица dmaslak.zakaz
DROP TABLE IF EXISTS `zakaz`;
CREATE TABLE IF NOT EXISTS `zakaz` (
  `n` int NOT NULL AUTO_INCREMENT,
  `data` date NOT NULL,
  `client` int NOT NULL,
  `tovar` int NOT NULL,
  `kolvo` int NOT NULL DEFAULT '0',
  `opl` enum('Y','N') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`n`) USING BTREE,
  UNIQUE KEY `id_zakaz` (`n`) USING BTREE,
  KEY `FKtovar` (`tovar`) USING BTREE,
  KEY `FKclientz` (`client`) USING BTREE,
  CONSTRAINT `FKclientz` FOREIGN KEY (`client`) REFERENCES `klient` (`n`),
  CONSTRAINT `FKtovar` FOREIGN KEY (`tovar`) REFERENCES `tovar` (`n`)
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список заказов п 10';

-- Дамп данных таблицы dmaslak.zakaz: ~4 rows (приблизительно)
DELETE FROM `zakaz`;
/*!40000 ALTER TABLE `zakaz` DISABLE KEYS */;
INSERT INTO `zakaz` (`n`, `data`, `client`, `tovar`, `kolvo`, `opl`) VALUES
	(1, '2021-03-24', 6, 8, 3, ''),
	(2, '2021-05-05', 9, 10, 1, ''),
	(3, '2021-02-28', 1, 10, 3, ''),
	(4, '2021-01-13', 4, 4, 1, '');
/*!40000 ALTER TABLE `zakaz` ENABLE KEYS */;

-- Дамп структуры для представление dmaslak.viewa
DROP VIEW IF EXISTS `viewa`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `viewa`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `viewa` AS select `i`.`name` AS `name` from (`izgot` `i` join `tovar` `t` on((`i`.`n` = `t`.`izgot`))) where ((`t`.`name` = 'Лампы') and (`t`.`cena` < 30));

-- Дамп структуры для представление dmaslak.viewb
DROP VIEW IF EXISTS `viewb`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `viewb`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `viewb` AS select `p`.`nazv` AS `naz` from (`postav` `p` join `schet` `s`) where ((`p`.`schet` = `s`.`n`) and (`s`.`bank` = 'Bank BNP Paribas') and (`s`.`data` = '2015-11-18') and (`s`.`cr` = 'Y')) union select `p`.`fio` AS `naz` from (`klient` `p` join `schet` `s`) where ((`p`.`schet` = `s`.`n`) and (`s`.`bank` = 'Bank BNP Paribas') and (`s`.`data` = '2015-11-18') and (`s`.`cr` = 'Y')) union select `p`.`firma` AS `naz` from (`firma` `p` join `schet` `s`) where ((`p`.`schet` = `s`.`n`) and (`s`.`bank` = 'Bank BNP Paribas') and (`s`.`data` = '2015-11-18') and (`s`.`cr` = 'Y'));

-- Дамп структуры для представление dmaslak.viewc
DROP VIEW IF EXISTS `viewc`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `viewc`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `viewc` AS select `firma`.`uradr` AS `uradr`,`firma`.`telefon` AS `telefon` from `firma` where (`firma`.`firma` = 'com40');

-- Дамп структуры для представление dmaslak.viewd
DROP VIEW IF EXISTS `viewd`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `viewd`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `viewd` AS select `s`.`N` AS `n` from ((`sklad` `s` join `izgot` `i`) join `tovar` `t`) where ((`t`.`izgot` = `i`.`n`) and (`t`.`sklad` = `s`.`N`) and (`t`.`name` = 'Кресла') and (`i`.`name` = 'ЧПТУП "ИНФОЦЕНТР"'));

-- Дамп структуры для представление dmaslak.viewe
DROP VIEW IF EXISTS `viewe`;
-- Удаление временной таблицы и создание окончательной структуры представления
DROP TABLE IF EXISTS `viewe`;
CREATE ALGORITHM=UNDEFINED SQL SECURITY DEFINER VIEW `viewe` AS select `s`.`bank` AS `bank` from (`klient` `k` join `schet` `s`) where ((`k`.`schet` = `s`.`n`) and (`k`.`n` = 5));

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
