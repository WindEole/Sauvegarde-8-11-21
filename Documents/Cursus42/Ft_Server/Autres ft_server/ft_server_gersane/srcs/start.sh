#Disable the autoindex if AUTOINDEX ENV variable is set to off
if [ $AUTOINDEX = "off" ]
then
	sed -i 's/autoindex on/autoindex off/g' /etc/nginx/sites-available/localhost
fi

openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/localhost.key -out /etc/ssl/localhost.pem -subj "/C=FR/L=PARIS/O=42PARIS"

#Configure 	Wordpress database
service mysql start
echo "CREATE DATABASE wordpress;"| mysql -u root --skip-password
echo "CREATE USER 'gersane'@'localhost' IDENTIFIED BY 'password';" | mysql -u root --skip-password
echo "GRANT ALL PRIVILEGES ON wordpress.* TO 'gersane'@'localhost';"| mysql -u root --skip-password
echo "FLUSH PRIVILEGES;"| mysql -u root --skip-password

#Allow all services to start
service php7.3-fpm start
service nginx start

bash
