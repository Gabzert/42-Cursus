FROM debian:stable

RUN apt-get update && \
    apt-get install -y wget apt-transport-https gnupg2 && \
    rm -rf /var/lib/apt/lists/*

RUN wget -q -O - https://packages.grafana.com/gpg.key | apt-key add - && \
    echo "deb https://packages.grafana.com/oss/deb stable main" > /etc/apt/sources.list.d/grafana.list

RUN apt-get update && \
    apt-get install -y grafana

COPY grafana.ini /etc/grafana/grafana.ini
RUN cp /var/tmp/grafana/shared/gfantech.42.fr.cert /etc/ssl
RUN cp /var/tmp/grafana/shared/gfantech.42.fr.key /etc/ssl

EXPOSE 3000

# Start Grafana service
CMD ["/usr/sbin/grafana-server", "--config=/etc/grafana/grafana.ini", "--homepath=/usr/share/grafana", "cfg:default.paths.data=/var/lib/grafana", "cfg:default.paths.logs=/var/log/grafana"]