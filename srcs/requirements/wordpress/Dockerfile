From	debian:10

# Update and install wordpress
RUN apt update
RUN apt install wget -y
RUN mkdir -p /var/www/html/
RUN wget -qO- http://wordpress.org/latest.tar.gz | tar xvz -C /var/www/html/
RUN chown -R www-data:www-data /var/www/html
RUN apt install mariadb-client php-fpm php-mysqli php-mysql -y
RUN mkdir -p /var/run/php

COPY requirements/wordpress/conf/www.conf /etc/php/7.3/fpm/pool.d/www.conf
COPY requirements/wordpress/conf/php.ini /etc/php/7.3/fpm/php.ini

EXPOSE 9000 
EXPOSE 3306 

CMD ["/usr/sbin/php-fpm7.3", "--nodaemonize"]
