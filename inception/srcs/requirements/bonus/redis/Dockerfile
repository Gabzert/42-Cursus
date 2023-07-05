FROM debian:stable


RUN apt-get update && apt-get install -y redis && rm -rf /var/lib/apt/lists/*

EXPOSE 6379

COPY ./redis.sh /usr/bin/redis.sh

CMD [ "sh", "/usr/bin/redis.sh" ]