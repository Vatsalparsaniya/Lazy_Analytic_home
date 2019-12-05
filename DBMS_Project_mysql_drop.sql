ALTER TABLE `Power_consumption` DROP FOREIGN KEY `Power_consumption_fk0`;

ALTER TABLE `Alexa_Equipment` DROP FOREIGN KEY `Alexa_Equipment_fk0`;

ALTER TABLE `Alexa_Equipment` DROP FOREIGN KEY `Alexa_Equipment_fk1`;

ALTER TABLE `Humidity_sensor` DROP FOREIGN KEY `Humidity_sensor_fk0`;

ALTER TABLE `Temperature_sensor copy` DROP FOREIGN KEY `Temperature_sensor copy_fk0`;

ALTER TABLE `Sound_sensor copy copy` DROP FOREIGN KEY `Sound_sensor copy copy_fk0`;

ALTER TABLE `command_related_sensor` DROP FOREIGN KEY `command_related_sensor_fk0`;

ALTER TABLE `command_related_sensor` DROP FOREIGN KEY `command_related_sensor_fk1`;

DROP TABLE IF EXISTS `Sensor_discription`;

DROP TABLE IF EXISTS `Equipment`;

DROP TABLE IF EXISTS `Power_consumption`;

DROP TABLE IF EXISTS `Alexa_Equipment`;

DROP TABLE IF EXISTS `Humidity_sensor`;

DROP TABLE IF EXISTS `Temperature_sensor copy`;

DROP TABLE IF EXISTS `Sound_sensor copy copy`;

DROP TABLE IF EXISTS `Alexa_general_command`;

DROP TABLE IF EXISTS `command_related_sensor`;

