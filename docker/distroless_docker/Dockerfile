FROM golang:1.9 as build

WORKDIR /
COPY . /go/src/github.com/gihyodocker/todoapi
RUN go get github.com/go-sql-driver/mysql
RUN go get gopkg.in/gorp.v1
RUN cd /go/src/github.com/gihyodocker/todoapi && go build -o bin/todoapi cmd/main.go

FROM gcr.io/distroless/base
COPY --from=build /go/src/github.com/gihyodocker/todoapi/bin/todoapi /usr/local/bin/
CMD ["todoapi"]