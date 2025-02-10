NAMECLIENT = client
NAMESERVER = server
NAMECLIENT_BONUS = client_bonus
NAMESERVER_BONUS = server_bonus

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCC = client.c ft_atoi.c ft_putnbr.c ft_putchar.c
SRCS = server.c ft_atoi.c ft_putnbr.c ft_putchar.c
SRCC_BONUS = client_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c 
SRCS_BONUS = server_bonus.c ft_atoi.c ft_putnbr.c ft_putchar.c ft_bzero.c helper_bonus.c

OBJC = $(SRCC:.c=.o)
OBJS = $(SRCS:.c=.o)
OBJC_BONUS = $(SRCC_BONUS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: $(NAMECLIENT) $(NAMESERVER)

$(NAMECLIENT): $(OBJC)
	$(CC) $(CFLAGS) $(OBJC) -o $(NAMECLIENT)

$(NAMESERVER): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAMESERVER)

bonus: $(NAMECLIENT_BONUS) $(NAMESERVER_BONUS)

$(NAMECLIENT_BONUS): $(OBJC_BONUS)
	$(CC) $(CFLAGS) $(OBJC_BONUS) -o $(NAMECLIENT_BONUS)

$(NAMESERVER_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -o $(NAMESERVER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJC) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMECLIENT_BONUS) $(NAMESERVER_BONUS)

re: fclean all
