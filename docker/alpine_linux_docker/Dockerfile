FROM alpine:3.7

WORKDIR /
ENV GOPATH /go

RUN apk add --no-cache --virtual=build-deps go git gcc g++

RUN apk add --no-cache ca-certificates

COPY . /go/src/github.com/gihyodocker/todoapi
RUN go get github.com/go-sql-driver/mysql
RUN go get gopkg.in/gorp.v1
RUN cd /go/src/github.com/gihyodocker/todoapi && go build -o bin/todoapi cmd/main.go
RUN cd /go/src/github.com/gihyodocker/todoapi && cp bin/todoapi /usr/local/bin/

RUN apk del --no-cache build-deps

CMD ["todoapi"]