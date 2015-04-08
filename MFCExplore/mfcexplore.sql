#Create database mfcexplore
CREATE DATABASE mfcexplore;
USE mfcexplore;

#Dumping table structure of contacts
CREATE TABLE `contacts` (
  `name` varchar(40) NOT NULL,
  `mobilephone` varchar(16) NOT NULL,
  PRIMARY KEY (`name`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
