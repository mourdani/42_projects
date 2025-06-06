FROM debian:10

# Update and install nginx
RUN apt update 
RUN apt install -y nginx

# Create ssl directory and copy certificates
RUN mkdir /etc/ssl
COPY	requirements/nginx/tools/mourdani.42.fr.crt \
	/etc/ssl/mourdani.42.fr.crt
COPY	requirements/nginx/tools/mourdani.42.fr.key \
	/etc/ssl/mourdani.42.fr.key

# Copy nginx conf file
COPY requirements/nginx/conf/nginx.conf /etc/nginx/nginx.conf

# Listen on 443 (HTTPS)
EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
