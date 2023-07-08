FROM debian:stable

RUN apt-get update && apt-get install -y \
	nginx\
	&& rm -rf /var/lib/apt/lists/*

EXPOSE 8080

COPY static.conf /etc/nginx/conf.d

COPY web-data /tmp/web-data

RUN mv /tmp/web-data/* /usr/share/nginx/html

# RUN ln -sf /dev/stdout /var/log/nginx/access.log
# RUN ln -sf /dev/stderr /var/log/nginx/error.log


CMD ["nginx", "-g", "daemon off;"]