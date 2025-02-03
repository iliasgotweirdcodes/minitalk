NAMEC = client
NAMES = server

CC = cc
CFLAGS = -Wall -Werror -Wextra
INCLUDE = -I minitalk.h
RM = rm -rf

SRCC = client.c ft_atoi.c ft_putnbr.c ft_putchar.c
SRCS = server.c ft_atoi.c ft_putnbr.c ft_putchar.c

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)

all: $(NAMEC) $(NAMES)


$(NAMEC): $(OBJC) minitalk.h
	$(CC) $(CFLAGS) $(OBJC)  -o $(NAMEC)

$(NAMES): $(OBJS) minitalk.h
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAMES)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJC) $(OBJS)

fclean: clean
	$(RM) $(NAMEC) $(NAMES)

re: fclean all
