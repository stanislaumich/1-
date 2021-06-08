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


-- Дамп структуры базы данных a_5242201_21_09
DROP DATABASE IF EXISTS `a_5242201_21_09`;
CREATE DATABASE IF NOT EXISTS `a_5242201_21_09` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `a_5242201_21_09`;

-- Дамп структуры для таблица a_5242201_21_09.a_5242201_21_09_petname
DROP TABLE IF EXISTS `a_5242201_21_09_petname`;
CREATE TABLE IF NOT EXISTS `a_5242201_21_09_petname` (
  `Pet_id` int unsigned NOT NULL,
  `Pet_name` varchar(20) DEFAULT NULL,
  `Owner` varchar(15) DEFAULT NULL,
  `massa` int DEFAULT NULL,
  `Vid` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci DEFAULT 'www',
  `PetBirth` date DEFAULT NULL,
  `town` char(50) DEFAULT NULL,
  PRIMARY KEY (`Pet_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы a_5242201_21_09.a_5242201_21_09_petname: ~5 rows (приблизительно)
DELETE FROM `a_5242201_21_09_petname`;
/*!40000 ALTER TABLE `a_5242201_21_09_petname` DISABLE KEYS */;
INSERT INTO `a_5242201_21_09_petname` (`Pet_id`, `Pet_name`, `Owner`, `massa`, `Vid`, `PetBirth`, `town`) VALUES
	(1, 'БобикМикулич21', 'ИвановМикулич21', 300, 'КотМСВ21', '2021-01-20', 'MOG'),
	(3, 'ШарикМикулич21', 'СидорМикулич21', 500, 'ЗмеяСВ21', '2020-01-20', 'MOG'),
	(4, 'ЖучМикулич21', 'СидорМикулич21', 800, 'КотСВ21', '2019-01-20', 'MOG'),
	(6, 'БобМикулич21', 'ПетровМикулич21', 400, 'КотМСВ21', '2019-01-01', 'MOG'),
	(7, 'РыжикМикулич21', 'ИвановМикулич21', 1500, 'СобМСВ21', '2017-01-20', 'MOG');
/*!40000 ALTER TABLE `a_5242201_21_09_petname` ENABLE KEYS */;


-- Дамп структуры базы данных b_01_21_09
DROP DATABASE IF EXISTS `b_01_21_09`;
CREATE DATABASE IF NOT EXISTS `b_01_21_09` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `b_01_21_09`;

-- Дамп структуры для таблица b_01_21_09.avt_01_21_09
DROP TABLE IF EXISTS `avt_01_21_09`;
CREATE TABLE IF NOT EXISTS `avt_01_21_09` (
  `avt_id` int unsigned NOT NULL,
  `a_firstname` varchar(50) DEFAULT NULL,
  `a_lastname` varchar(40) DEFAULT NULL,
  `birthd` date DEFAULT NULL,
  `sex` enum('М','Ж') DEFAULT NULL,
  `town` int DEFAULT NULL,
  PRIMARY KEY (`avt_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы b_01_21_09.avt_01_21_09: ~0 rows (приблизительно)
DELETE FROM `avt_01_21_09`;
/*!40000 ALTER TABLE `avt_01_21_09` DISABLE KEYS */;
INSERT INTO `avt_01_21_09` (`avt_id`, `a_firstname`, `a_lastname`, `birthd`, `sex`, `town`) VALUES
	(1, 'Сергей', 'Иванов', '1940-01-08', 'М', 1),
	(2, 'Андрей', 'Петров', '1950-02-08', 'М', 2),
	(3, 'Василий', 'Сидоров', '1960-03-08', 'М', 1),
	(4, 'Николай', 'Лукьянов', '1970-04-08', 'Ж', 2),
	(5, 'Петр', 'Григорьев', '1980-05-08', 'Ж', 3),
	(6, 'Николай', 'Митрофанов', '1990-06-08', 'Ж', 4),
	(7, 'Андрей', 'Степанов', '1980-07-08', 'М', 3),
	(8, 'Иван', 'Федорцов', '1970-08-08', 'М', 4),
	(9, 'Сергей', 'Кешкин', '1960-09-08', 'Ж', 3);
/*!40000 ALTER TABLE `avt_01_21_09` ENABLE KEYS */;

-- Дамп структуры для таблица b_01_21_09.book_01_21_09
DROP TABLE IF EXISTS `book_01_21_09`;
CREATE TABLE IF NOT EXISTS `book_01_21_09` (
  `book_id` int unsigned NOT NULL AUTO_INCREMENT,
  `book_name` varchar(10) DEFAULT NULL,
  `avt_id` int unsigned DEFAULT NULL,
  `Student` int DEFAULT '12109',
  PRIMARY KEY (`book_id`),
  KEY `avt_id` (`avt_id`),
  CONSTRAINT `avt_id` FOREIGN KEY (`avt_id`) REFERENCES `avt_01_21_09` (`avt_id`)
) ENGINE=InnoDB AUTO_INCREMENT=7 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_0900_ai_ci;

-- Дамп данных таблицы b_01_21_09.book_01_21_09: ~0 rows (приблизительно)
DELETE FROM `book_01_21_09`;
/*!40000 ALTER TABLE `book_01_21_09` DISABLE KEYS */;
INSERT INTO `book_01_21_09` (`book_id`, `book_name`, `avt_id`, `Student`) VALUES
	(1, 'Библия', 2, 12109),
	(2, 'Учебник', 4, 12109),
	(3, 'Пособие', 6, 12109),
	(4, 'Журнал', 3, 12109),
	(5, 'Монография', 1, 12109),
	(6, 'Раскраска', 6, 12109);
/*!40000 ALTER TABLE `book_01_21_09` ENABLE KEYS */;

/*!40101 SET SQL_MODE=IFNULL(@OLD_SQL_MODE, '') */;
/*!40014 SET FOREIGN_KEY_CHECKS=IFNULL(@OLD_FOREIGN_KEY_CHECKS, 1) */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40111 SET SQL_NOTES=IFNULL(@OLD_SQL_NOTES, 1) */;
