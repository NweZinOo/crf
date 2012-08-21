-- phpMyAdmin SQL Dump
-- version 3.2.4
-- http://www.phpmyadmin.net
--
-- 主机: localhost
-- 生成日期: 2012 年 06 月 23 日 12:37
-- 服务器版本: 5.1.41
-- PHP 版本: 5.3.1

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- 数据库: `crf`
--

-- --------------------------------------------------------

--
-- 表的结构 `apply`
--

CREATE TABLE IF NOT EXISTS `apply` (
  `p_uid` int(11) NOT NULL AUTO_INCREMENT,
  `hospital_no` varchar(255) NOT NULL,
  `hospital_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `sift` varchar(255) NOT NULL,
  `p_name` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `p_birthday` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `approved` tinyint(4) NOT NULL,
  `approved_time` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  `team` tinyint(4) NOT NULL,
  `apply_time` varchar(255) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`p_uid`)
) ENGINE=MyISAM  DEFAULT CHARSET=latin1 AUTO_INCREMENT=10 ;

--
-- 转存表中的数据 `apply`
--

INSERT INTO `apply` (`p_uid`, `hospital_no`, `hospital_name`, `sift`, `p_name`, `p_birthday`, `approved`, `approved_time`, `team`, `apply_time`) VALUES
(6, '01', '复旦大学附属肿瘤医院', '1', 'abcd', '2012-06-11', 0, '2012-06-12', 2, '2012-06-23 16:26:49'),
(7, '01', '复旦大学附属肿瘤医院', '1', 'abcd', '2012-06-18', 1, '2012-06-14', 2, '2012-06-23 16:29:14'),
(8, '01', '复旦大学附属肿瘤医院', '001', 'abcd', '2012-06-19', 1, '2012-06-12', 1, '2012-06-23 16:30:19'),
(9, '01', '复旦大学附属肿瘤医院', '001', 'abcd', '2012-06-11', 1, '2012-06-06', 1, '2012-06-23 18:07:31');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
