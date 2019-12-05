CREATE TABLE `Sensor_discription` (
	`Sensor_id` int NOT NULL AUTO_INCREMENT,
	`Sensor_Name` varchar(255) NOT NULL UNIQUE,
	`Sensor_discription` varchar(255),
	`sensor_type` bigint NOT NULL,
	`number of sensor` bigint NOT NULL,
	`power_consumption` double NOT NULL,
	PRIMARY KEY (`Sensor_id`)
);

CREATE TABLE `Equipment` (
	`Equipment_id` int NOT NULL AUTO_INCREMENT,
	`Equipment_name` varchar(255) NOT NULL,
	`Equipment_Location` varchar(255) NOT NULL,
	`Equipment_Work` varchar(255) NOT NULL,
	`Power_consumption` double(255) NOT NULL,
	`Equipment_status` bigint NOT NULL,
	PRIMARY KEY (`Equipment_id`)
);

CREATE TABLE `Power_consumption` (
	`Equipment _id` int NOT NULL AUTO_INCREMENT,
	`Start_time` TIMESTAMP NOT NULL,
	`End_time` TIMESTAMP NOT NULL,
	`RS.` double NOT NULL,
	PRIMARY KEY (`Equipment _id`,`Start_time`)
);

CREATE TABLE `Alexa_Equipment` (
	`Alexa_command_id` varchar(255) NOT NULL,
	`Equipment_id` int NOT NULL,
	PRIMARY KEY (`Alexa_command_id`,`Equipment_id`)
);

CREATE TABLE `Humidity_sensor` (
	`Time` TIMESTAMP NOT NULL,
	`Humidity_sensor_id` int(255) NOT NULL,
	`sensor_id` bigint NOT NULL,
	`Humidity_sensor_data` double(255) NOT NULL,
	`Humidity_sensor_Status` varchar(255) NOT NULL,
	`Location` varchar(255) NOT NULL,
	PRIMARY KEY (`Time`,`Humidity_sensor_id`)
);

CREATE TABLE `Temperature_sensor copy` (
	`Time` TIMESTAMP NOT NULL,
	`Temperature_sensor_id` int(255) NOT NULL,
	`sensor_id` bigint NOT NULL,
	`Temperature_sensor_data` double(255) NOT NULL,
	`Temperature_sensor_status` varchar(255) NOT NULL,
	`Location` varchar(255) NOT NULL,
	PRIMARY KEY (`Time`,`Temperature_sensor_id`)
);

CREATE TABLE `Sound_sensor copy copy` (
	`Time` TIMESTAMP NOT NULL,
	`Sound_sensor_id` int(255) NOT NULL,
	`sensor_id` bigint NOT NULL,
	`Sound_sensor_data` double(255) NOT NULL,
	`Sound_sensor_status` varchar(255) NOT NULL,
	`Location` varchar(255) NOT NULL,
	PRIMARY KEY (`Time`,`Sound_sensor_id`)
);

CREATE TABLE `Alexa_general_command` (
	`command_id` bigint NOT NULL AUTO_INCREMENT,
	`Alexa_command` varchar(500) NOT NULL,
	`related_query` varchar(500) NOT NULL,
	PRIMARY KEY (`command_id`)
);

CREATE TABLE `command_related_sensor` (
	`command_id` bigint NOT NULL AUTO_INCREMENT,
	`sensor_id` bigint NOT NULL AUTO_INCREMENT,
	PRIMARY KEY (`command_id`,`sensor_id`)
);

ALTER TABLE `Power_consumption` ADD CONSTRAINT `Power_consumption_fk0` FOREIGN KEY (`Equipment _id`) REFERENCES `Equipment`(`Equipment_id`);

ALTER TABLE `Alexa_Equipment` ADD CONSTRAINT `Alexa_Equipment_fk0` FOREIGN KEY (`Alexa_command_id`) REFERENCES `Alexa_general_command`(`command_id`);

ALTER TABLE `Alexa_Equipment` ADD CONSTRAINT `Alexa_Equipment_fk1` FOREIGN KEY (`Equipment_id`) REFERENCES `Equipment`(`Equipment_id`);

ALTER TABLE `Humidity_sensor` ADD CONSTRAINT `Humidity_sensor_fk0` FOREIGN KEY (`sensor_id`) REFERENCES `Sensor_discription`(`Sensor_id`);

ALTER TABLE `Temperature_sensor copy` ADD CONSTRAINT `Temperature_sensor copy_fk0` FOREIGN KEY (`Temperature_sensor_id`) REFERENCES `Sensor_discription`(`Sensor_id`);

ALTER TABLE `Sound_sensor copy copy` ADD CONSTRAINT `Sound_sensor copy copy_fk0` FOREIGN KEY (`Sound_sensor_id`) REFERENCES `Sensor_discription`(`Sensor_id`);

ALTER TABLE `command_related_sensor` ADD CONSTRAINT `command_related_sensor_fk0` FOREIGN KEY (`command_id`) REFERENCES `Alexa_general_command`(`command_id`);

ALTER TABLE `command_related_sensor` ADD CONSTRAINT `command_related_sensor_fk1` FOREIGN KEY (`sensor_id`) REFERENCES `Sensor_discription`(`Sensor_id`);

