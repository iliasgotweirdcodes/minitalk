NAMECLIENT = client
NAMESERVER = server
NAMECLIENT_BONUS = client_bonus
NAMESERVER_BONUS = server_bonus

HEADER = minitalk.h
HEADER_BONUS = minitalk_bonus.h

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRCC = mandatory/client.c mandatory/ft_atoi.c mandatory/ft_putnbr.c mandatory/ft_putchar.c
SRCS = mandatory/server.c mandatory/ft_atoi.c mandatory/ft_putnbr.c mandatory/ft_putchar.c
SRCC_BONUS = bonus/client_bonus.c bonus/ft_atoi_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_putchar_bonus.c
SRCS_BONUS = bonus/server_bonus.c bonus/ft_atoi_bonus.c bonus/ft_putnbr_bonus.c bonus/ft_putchar_bonus.c bonus/ft_bzero_bonus.c bonus/helper_bonus.c

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

$(OBJC) $(OBJS): $(HEADER)
$(OBJC_BONUS) $(OBJS_BONUS): $(HEADER_BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJC) $(OBJS) $(OBJC_BONUS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAMECLIENT) $(NAMESERVER) $(NAMECLIENT_BONUS) $(NAMESERVER_BONUS)

re: fclean all

