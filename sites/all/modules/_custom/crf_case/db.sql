/**
 * Create TABLE crf_case_data
 */
CREATE TABLE `crf_case_data` (
 `id` int(11) NOT NULL AUTO_INCREMENT,
 `uid` int(11) NOT NULL DEFAULT '0',
 `name` varchar(50) NOT NULL,
 `data` text NOT NULL,
 `updated` int(11) NOT NULL,
 PRIMARY KEY (`id`),
 UNIQUE KEY `uid_name` (`uid`,`name`)
)