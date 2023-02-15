FROM ubuntu:22.04 as base

RUN apt-get update && apt-get install -y build-essential

WORKDIR CPP

COPY ./CPP_piscine ./CPP_piscine

FROM base as test

COPY ./test.sh ./test.sh

ENTRYPOINT ["bash", "test.sh"]
