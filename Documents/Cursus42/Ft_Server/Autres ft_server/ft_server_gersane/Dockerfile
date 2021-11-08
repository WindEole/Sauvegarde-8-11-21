# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gsegbeay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 08:45:32 by gsegbeay          #+#    #+#              #
#    Updated: 2021/05/17 15:19:23 by gsegbeay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#OS
FROM	debian:buster

WORKDIR	/var/www/localhost

#install all services necessary
RUN		apt-get update -y && apt-get -y install \
		wget \
		nginx \
		mariadb-server \
		openssl \
		php7.3-fpm php7.3-mysql php7.3-cli php7.3-mbstring

#Nginx
COPY		srcs/nginx.conf /etc/nginx/sites-available/localhost
RUN		ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled/localhost && \
		rm -rf /etc/nginx/site-enabled/default

#PhpMyAdmin
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.0.1/phpMyAdmin-5.0.1-english.tar.gz && \
		tar -xzvf phpMyAdmin-5.0.1-english.tar.gz && \
		mv phpMyAdmin-5.0.1-english/ /var/www/localhost/phpmyadmin && \
		rm -rf phpMyAdmin-5.0.1-english.tar.gz && \
		rm -rf /var/www/localhost/phpmyadmin/config.sample.inc.php
COPY	./srcs/config.inc.php /var/www/localhost/phpmyadmin

#Wordpress
RUN		wget https://wordpress.org/latest.tar.gz && \
		tar -xzvf latest.tar.gz && \
		rm -rf latest.tar.gz
COPY	./srcs/wp-config.php /var/www/localhost/

COPY	./srcs/start.sh /var/www/localhost

#Change folder rights
RUN		chown -R www-data:www-data /var/www/* && \
		chmod -R 755 /var/www/* && \
		chmod 777 /var/www/localhost/start.sh

ENV		AUTOINDEX="on"

EXPOSE		80 443

CMD		"./start.sh"
