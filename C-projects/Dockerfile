FROM ubuntu:22.04 as base

RUN apt-get update && apt-get install -y build-essential \
	libreadline-dev

WORKDIR codam_projects

COPY ./libft ./libft
COPY ./ft_printf ./ft_printf
COPY ./get_next_line ./get_next_line
COPY ./pushswap ./pushswap
COPY ./minishell ./minishell
COPY ./philosophers ./philosophers

FROM base as test

COPY ./test_compile.sh ./test_compile.sh

ENTRYPOINT ["bash", "./test_compile.sh"]
