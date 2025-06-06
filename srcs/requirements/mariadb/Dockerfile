From	debian:10

# Update and install wordpress
# install mariadb
RUN apt update
RUN apt install mariadb-server -y
RUN usermod -u 1001 mysql; groupmod -g 1001 mysql
RUN chown -R mysql:mysql /var/lib/mysql


# Copy nginx conf file
COPY requirements/mariadb/conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf

# listen on port 3306
EXPOSE 3306

# start mariadb daemon
CMD ["mysqld_safe"]
