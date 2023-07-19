FROM debian:stable

RUN apt-get update && apt-get install -y wget \
    && rm -rf /var/lib/apt/lists/*

RUN wget https://github.com/google/cadvisor/releases/download/v0.37.0/cadvisor \
    && chmod +x cadvisor

EXPOSE 8080

CMD ["./cadvisor"]