# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/17 10:40:20 by iderighe          #+#    #+#              #
#    Updated: 2021/05/20 13:18:56 by iderighe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS (installe l'image de base)
FROM	debian:buster

# Dossier de travail (qui contiendra les infos pour batir le site web)
WORKDIR	/var/www/localhost
COPY	./srcs/init_container.sh /var/www/

# UPDATE
RUN		apt-get update && apt-get -y upgrade

# Telecharge et installe les services dont on aura besoin
RUN		apt-get -y install \
		wget \
		nginx \
		mariadb-server \
		openssl # outil de cryptographie pour le protocole Secure Socket Layer

# PHP7.3 : langage pour creer des sites web dynamiques
RUN		apt-get -y install php7.3-fpm php7.3-common php7.3-mysql php7.3-gmp php7.3-curl php7.3-intl php7.3-mbstring php7.3-xmlrpc php7.3-gd php7.3-xml php7.3-cli php7.3-zip php7.3-soap php7.3-imap

# NGINX (install & config) paauet Nginx : logiciel libre de serveur Web
RUN		ln -s /etc/nginx/sites-available/localhost /etc/nginx/sites-enabled && \
		rm -rf /etc/nginx/sites-enabled/default
COPY	./srcs/nginx.conf /etc/nginx/sites-available/localhost

# PHPMYADMIN
RUN		wget https://files.phpmyadmin.net/phpMyAdmin/5.1.0/phpMyAdmin-5.1.0-english.tar.gz && \
		tar xzf phpMyAdmin-5.1.0-english.tar.gz && \
		rm -rf phpMyAdmin-5.1.0-english.tar.gz && \
		mv phpMyAdmin-5.1.0-english phpmyadmin
COPY	./srcs/phpmyadmin.inc.php /var/www/localhost/phpmyadmin/config.inc.php

# WORDPRESS
RUN		wget https://wordpress.org/latest.tar.gz && \
		tar xzf latest.tar.gz && \
		rm -rf latest.tar.gz
COPY	./srcs/wp-config.php /var/www/localhost/wordpress/wp-config.php

# Change rights
RUN		chown -R www-data:www-data /var/www/localhost && \
		chmod 755 -R /var/www/localhost && \
		chmod 777 /var/www/init_container.sh

# Ports that needs to be exposed at run time with -p [host port]:[container port]
EXPOSE	80 443

# Definition de la variable Autoindex (set sur on par defaut)
ENV		AUTOINDEX="on"

# START SERVER
CMD		bash /var/www/init_container.sh
