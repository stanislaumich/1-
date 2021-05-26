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


-- Дамп структуры базы данных pas-trans
DROP DATABASE IF EXISTS `pas-trans`;
CREATE DATABASE IF NOT EXISTS `pas-trans` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `pas-trans`;

-- Дамп структуры для таблица pas-trans.firma
DROP TABLE IF EXISTS `firma`;
CREATE TABLE IF NOT EXISTS `firma` (
  `nazvan` varchar(500) NOT NULL DEFAULT '',
  `uradr` varchar(500) NOT NULL DEFAULT '',
  `phone` varchar(50) NOT NULL DEFAULT '',
  `idschet` int NOT NULL,
  UNIQUE KEY `FKschetf` (`idschet`) USING BTREE,
  CONSTRAINT `FKschetf` FOREIGN KEY (`idschet`) REFERENCES `schet` (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Описание фирмы';

-- Дамп данных таблицы pas-trans.firma: ~1 rows (приблизительно)
DELETE FROM `firma`;
/*!40000 ALTER TABLE `firma` DISABLE KEYS */;
INSERT INTO `firma` (`nazvan`, `uradr`, `phone`, `idschet`) VALUES
	('ПАС-Транс', 'г. Бобруйск, ул. Гоголя, д.166-В, оф. 301', '+375 29 620 84 00', 1);
/*!40000 ALTER TABLE `firma` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.kadry
DROP TABLE IF EXISTS `kadry`;
CREATE TABLE IF NOT EXISTS `kadry` (
  `idkadry` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) NOT NULL,
  `dolgznost` varchar(500) NOT NULL,
  `obrazovanie` enum('Среднее','Среднее-специальное','Высшее') CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `zarplata` float unsigned NOT NULL,
  `data_priniatia` date NOT NULL,
  `IDSCHET` int DEFAULT NULL,
  PRIMARY KEY (`idkadry`),
  UNIQUE KEY `idkadr` (`idkadry`),
  KEY `FK_kadry_schet` (`IDSCHET`),
  CONSTRAINT `FK_kadry_schet` FOREIGN KEY (`IDSCHET`) REFERENCES `schet` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Сотрудники фирмы';

-- Дамп данных таблицы pas-trans.kadry: ~6 rows (приблизительно)
DELETE FROM `kadry`;
/*!40000 ALTER TABLE `kadry` DISABLE KEYS */;
INSERT INTO `kadry` (`idkadry`, `fio`, `dolgznost`, `obrazovanie`, `zarplata`, `data_priniatia`, `IDSCHET`) VALUES
	(1, 'Парахневич А.С.', 'Директор', 'Высшее', 945, '2018-02-20', NULL),
	(2, 'Аверкова И.В.', 'Бухгалтер', 'Высшее', 750, '2018-02-20', NULL),
	(3, 'Долбик К.В.', 'Водитель', 'Среднее-специальное', 550, '2020-02-20', NULL),
	(4, 'Савицкий А.Н.', 'Менеджер ', 'Среднее-специальное', 600, '2020-02-20', NULL),
	(5, 'Зарянина Т.Н.', 'Продавец', 'Среднее-специальное', 550, '2020-02-20', NULL),
	(6, 'Авхимович С. Н.', 'Экспедитор', 'Среднее', 120, '2021-05-25', NULL);
/*!40000 ALTER TABLE `kadry` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.klient
DROP TABLE IF EXISTS `klient`;
CREATE TABLE IF NOT EXISTS `klient` (
  `idklient` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(250) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `idschet` int DEFAULT NULL,
  PRIMARY KEY (`idklient`),
  UNIQUE KEY `idclient` (`idklient`),
  KEY `FKschet` (`idschet`),
  CONSTRAINT `FKschet` FOREIGN KEY (`idschet`) REFERENCES `schet` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы pas-trans.klient: ~5 rows (приблизительно)
DELETE FROM `klient`;
/*!40000 ALTER TABLE `klient` DISABLE KEYS */;
INSERT INTO `klient` (`idklient`, `fio`, `uradr`, `idschet`) VALUES
	(1, 'Говрицов А.К.', 'г. Бобруйск, ул. Крылова, 152', 5),
	(2, 'Иванов К.А.', 'г. Минск, ул. Радиальная, 11', 6),
	(3, 'Максимова А.Г.', 'г. Жодино, ул. Неманская, 15-6', 7),
	(4, 'Мавриков П.К.', 'г. Бобруйск, ул. Минская, 14-2', NULL),
	(5, 'Парахневич С.А.', 'г. Рогачев, ул. Юбилейная, 23', NULL);
/*!40000 ALTER TABLE `klient` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.nakladnaya
DROP TABLE IF EXISTS `nakladnaya`;
CREATE TABLE IF NOT EXISTS `nakladnaya` (
  `idnakladnaya` int NOT NULL AUTO_INCREMENT,
  `idtovar` int NOT NULL,
  `kolvo` int unsigned NOT NULL,
  `summa` float unsigned NOT NULL,
  `idklient` int NOT NULL,
  PRIMARY KEY (`idnakladnaya`),
  UNIQUE KEY `idnaklad` (`idnakladnaya`),
  KEY `FKtovarn` (`idtovar`),
  KEY `FK_nakladnaya_klient` (`idklient`),
  CONSTRAINT `FK_nakladnaya_klient` FOREIGN KEY (`idklient`) REFERENCES `klient` (`idklient`),
  CONSTRAINT `FKtovarn` FOREIGN KEY (`idtovar`) REFERENCES `tovar` (`idtovar`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Накладные на товар';

-- Дамп данных таблицы pas-trans.nakladnaya: ~2 rows (приблизительно)
DELETE FROM `nakladnaya`;
/*!40000 ALTER TABLE `nakladnaya` DISABLE KEYS */;
INSERT INTO `nakladnaya` (`idnakladnaya`, `idtovar`, `kolvo`, `summa`, `idklient`) VALUES
	(1, 1, 3, 60, 1),
	(2, 2, 5, 100, 2);
/*!40000 ALTER TABLE `nakladnaya` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.postav
DROP TABLE IF EXISTS `postav`;
CREATE TABLE IF NOT EXISTS `postav` (
  `idpostav` int NOT NULL AUTO_INCREMENT,
  `fio` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `uradr` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `idschet` int DEFAULT NULL,
  PRIMARY KEY (`idpostav`),
  UNIQUE KEY `idpostav` (`idpostav`),
  KEY `FKschetp` (`idschet`),
  CONSTRAINT `FKschetp` FOREIGN KEY (`idschet`) REFERENCES `schet` (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Поставщики';

-- Дамп данных таблицы pas-trans.postav: ~6 rows (приблизительно)
DELETE FROM `postav`;
/*!40000 ALTER TABLE `postav` DISABLE KEYS */;
INSERT INTO `postav` (`idpostav`, `fio`, `uradr`, `idschet`) VALUES
	(1, 'ООО СВ-ТрансЛигистик', 'Не указано', 4),
	(2, 'ИП Тишкевич А.Т.', 'Не указано', 3),
	(3, 'ООО СимулПлюс', 'Не указано', 2),
	(4, 'ЧТУП Сом-Трак', 'Не указано', 3),
	(5, 'ЧТУП АксаЛайт', 'Не указано', 2),
	(6, 'Авхимович С. Н.', 'Не указано', 5);
/*!40000 ALTER TABLE `postav` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.schet
DROP TABLE IF EXISTS `schet`;
CREATE TABLE IF NOT EXISTS `schet` (
  `id` int NOT NULL AUTO_INCREMENT,
  `bank` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `numchet` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `status` int NOT NULL DEFAULT '0',
  `data` date NOT NULL,
  `creditstat` enum('Y','N') NOT NULL,
  `creditsum` float unsigned NOT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE KEY `idschet` (`id`) USING BTREE
) ENGINE=InnoDB AUTO_INCREMENT=8 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы pas-trans.schet: ~7 rows (приблизительно)
DELETE FROM `schet`;
/*!40000 ALTER TABLE `schet` DISABLE KEYS */;
INSERT INTO `schet` (`id`, `bank`, `numchet`, `status`, `data`, `creditstat`, `creditsum`) VALUES
	(1, 'Паритетбанк', '251485758', 1250, '2020-05-19', 'Y', 8500),
	(2, 'Альфа-Банк', '251452854', 0, '2021-05-19', 'Y', 9520),
	(3, 'ВТББанк', '956256325', 0, '2021-05-19', 'Y', 9000),
	(4, 'Белгазпромбанк', '254152889', 200, '2021-05-19', 'Y', 8000),
	(5, 'Белгазпромбанк', '325856984', 0, '2021-05-19', 'N', 0),
	(6, 'Приорбанк', '233625990', 820, '2021-05-19', 'N', 0),
	(7, 'Белгазпромбанк', '000025215', 0, '2021-05-19', 'Y', 820);
/*!40000 ALTER TABLE `schet` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.sklad
DROP TABLE IF EXISTS `sklad`;
CREATE TABLE IF NOT EXISTS `sklad` (
  `Nsklad` int unsigned NOT NULL AUTO_INCREMENT,
  `adress` varchar(5000) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  PRIMARY KEY (`Nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы pas-trans.sklad: ~5 rows (приблизительно)
DELETE FROM `sklad`;
/*!40000 ALTER TABLE `sklad` DISABLE KEYS */;
INSERT INTO `sklad` (`Nsklad`, `adress`) VALUES
	(1, 'г.Бобруйск,ул. Гоголя,172'),
	(2, 'г. Минск, ул. Ленина,5-2'),
	(3, 'г.Гомель, ул. М.Хмельницкого,125'),
	(4, 'г. Бобруйск, ул. Крылова,15-32'),
	(5, 'г. Могилев, пл. Ленина, 14');
/*!40000 ALTER TABLE `sklad` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.tovar
DROP TABLE IF EXISTS `tovar`;
CREATE TABLE IF NOT EXISTS `tovar` (
  `idtovar` int NOT NULL AUTO_INCREMENT,
  `naimen` varchar(500) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `edizm` varchar(50) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL DEFAULT 'Не указано',
  `cena` int unsigned NOT NULL,
  `idpostav` int NOT NULL,
  `idsklad` int unsigned NOT NULL,
  `Kolvo` int unsigned NOT NULL,
  `sort` int NOT NULL,
  PRIMARY KEY (`idtovar`),
  UNIQUE KEY `idtovar` (`idtovar`),
  KEY `FKpostavt` (`idpostav`),
  KEY `FK_tovar_sklad` (`idsklad`) USING BTREE,
  CONSTRAINT `FK_tovar_sklad` FOREIGN KEY (`idsklad`) REFERENCES `sklad` (`Nsklad`),
  CONSTRAINT `FKpostavt` FOREIGN KEY (`idpostav`) REFERENCES `postav` (`idpostav`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список товаров нормализованный';

-- Дамп данных таблицы pas-trans.tovar: ~6 rows (приблизительно)
DELETE FROM `tovar`;
/*!40000 ALTER TABLE `tovar` DISABLE KEYS */;
INSERT INTO `tovar` (`idtovar`, `naimen`, `edizm`, `cena`, `idpostav`, `idsklad`, `Kolvo`, `sort`) VALUES
	(1, 'Ноутбук', 'шт', 1499, 1, 1, 28, 0),
	(2, 'Игровая приставка', 'шт', 2455, 2, 1, 21, 0),
	(3, 'Мышка', 'шт', 15, 1, 2, 16, 0),
	(4, 'Фен', 'шт', 59, 2, 2, 4, 0),
	(5, 'Телвизор', 'шт', 4500, 1, 2, 5, 0),
	(6, 'Мышка', 'шт', 10, 4, 1, 10, 0);
/*!40000 ALTER TABLE `tovar` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.transport
DROP TABLE IF EXISTS `transport`;
CREATE TABLE IF NOT EXISTS `transport` (
  `idtransport` int NOT NULL AUTO_INCREMENT,
  `nomer` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `marka` varchar(45) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `tonnag` float unsigned NOT NULL,
  `god` int unsigned NOT NULL,
  `vladelec` varchar(450) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NOT NULL,
  `data_perevozki` date DEFAULT NULL,
  `nsklad` int unsigned DEFAULT NULL,
  PRIMARY KEY (`idtransport`) USING BTREE,
  KEY `FK_transport_sklad` (`nsklad`),
  CONSTRAINT `FK_transport_sklad` FOREIGN KEY (`nsklad`) REFERENCES `sklad` (`Nsklad`)
) ENGINE=InnoDB AUTO_INCREMENT=6 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы pas-trans.transport: ~4 rows (приблизительно)
DELETE FROM `transport`;
/*!40000 ALTER TABLE `transport` DISABLE KEYS */;
INSERT INTO `transport` (`idtransport`, `nomer`, `marka`, `tonnag`, `god`, `vladelec`, `data_perevozki`, `nsklad`) VALUES
	(2, 'AI 5215-6', 'MAN', 24000, 2011, 'ПАС-Транс', NULL, NULL),
	(3, 'AM 2532-6', 'DAF', 15000, 2018, 'ПАС-Транс', NULL, NULL),
	(4, 'AK 1256-6', 'DAF', 24000, 2019, 'ПАС-Транс', NULL, NULL),
	(5, 'AI 6326-6', 'Volvo', 10000, 2010, 'ПАС-Транс', NULL, NULL);
/*!40000 ALTER TABLE `transport` ENABLE KEYS */;

-- Дамп структуры для таблица pas-trans.zakaz
DROP TABLE IF EXISTS `zakaz`;
CREATE TABLE IF NOT EXISTS `zakaz` (
  `id` int NOT NULL AUTO_INCREMENT,
  `data` date DEFAULT NULL,
  `id_client` int NOT NULL,
  `id_tovar` int NOT NULL,
  `kolvo` int unsigned NOT NULL DEFAULT '0',
  `opl` enum('Y','N') DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE,
  UNIQUE KEY `id_zakaz` (`id`) USING BTREE,
  KEY `FKtovar` (`id_tovar`),
  KEY `FKclientz` (`id_client`),
  CONSTRAINT `FKclientz` FOREIGN KEY (`id_client`) REFERENCES `klient` (`idklient`),
  CONSTRAINT `FKtovar` FOREIGN KEY (`id_tovar`) REFERENCES `tovar` (`idtovar`)
) ENGINE=InnoDB AUTO_INCREMENT=4 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci COMMENT='Список заказов п 10';

-- Дамп данных таблицы pas-trans.zakaz: ~3 rows (приблизительно)
DELETE FROM `zakaz`;
/*!40000 ALTER TABLE `zakaz` DISABLE KEYS */;
INSERT INTO `zakaz` (`id`, `data`, `id_client`, `id_tovar`, `kolvo`, `opl`) VALUES
	(1, '2021-05-19', 2, 2, 3, NULL),
	(2, '2021-05-19', 4, 3, 1, NULL),
	(3, '2021-05-22', 5, 3, 1, NULL);
/*!40000 ALTER TABLE `zakaz` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
