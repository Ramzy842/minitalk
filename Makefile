# Define the compiler
CC = cc

# Define the flags to pass to the compiler
CFLAGS = -Wall -Wextra -Werror

# Define the source files for the client executable
CLIENT_SRC = client.c client_utilities.c common_utilities.c

# Define the object files for the client executable, generated from the source files
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

# Define the name of the client executable to be generated
NAME_CLIENT = client

# Define the source files for the server executable
SERVER_SRC = server.c server_utilities.c common_utilities.c

# Define the object files for the server executable, generated from the source files
SERVER_OBJ = $(SERVER_SRC:.c=.o)

# Define the name of the server executable to be generated
NAME_SERVER = server

# Define the source files for the bonus client
CLIENT_BONUS_SRC = client_bonus.c client_utilities.c common_utilities.c

# Define the object files for the bonus client, generated from the source files
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

# Define the name of the bonus client to be generated
NAME_CLIENT_BONUS = client_bonus

# Define the source files for the bonus server
SERVER_BONUS_SRC = server_bonus.c server_utilities.c common_utilities.c

# Define the object files for the bonus server, generated from the source files
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)

# Define the name of the bonus server to be generated
NAME_SERVER_BONUS = server_bonus

# Define the default target to be built
all: $(NAME_CLIENT) $(NAME_SERVER)

# Rule to generate the client executable from the object files
$(NAME_CLIENT): $(CLIENT_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_OBJ) -o $(NAME_CLIENT)

# Rule to generate the server executable from the object files
$(NAME_SERVER): $(SERVER_OBJ)
	$(CC) $(CFLAGS) $(SERVER_OBJ) -o $(NAME_SERVER)

# Rule to generate the client bonus executable from the object files
$(NAME_CLIENT_BONUS): $(CLIENT_BONUS_OBJ)
	$(CC) $(CFLAGS) $(CLIENT_BONUS_OBJ) -o $(NAME_CLIENT_BONUS)

# Rule to generate the server bonus executable from the object files
$(NAME_SERVER_BONUS): $(SERVER_BONUS_OBJ)
	$(CC) $(CFLAGS) $(SERVER_BONUS_OBJ) -o $(NAME_SERVER_BONUS)

# Bonus
bonus: $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

# Rule to generate the object files from the source files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Clean target to remove generated files
clean:
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) $(CLIENT_BONUS_OBJ) $(SERVER_BONUS_OBJ)

# Fclean target to remove executable files and perform clean
fclean: clean
	rm -f $(NAME_CLIENT) $(NAME_SERVER) $(NAME_CLIENT_BONUS) $(NAME_SERVER_BONUS)

# Re target to rebuild the project from scratch
re: fclean all

.PHONY: all clean fclean


