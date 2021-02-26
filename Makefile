SRCS			=	srcs/ft_strlen.s			\
					srcs/ft_write.s				\
					srcs/ft_read.s				\
					srcs/ft_strcpy.s			\
					srcs/ft_strcmp.s			\
					srcs/ft_strdup.s			\

OBJS			=	$(SRCS:.s=.o)

ASM				=	nasm
ASM_FLAG		=	-f elf64
RM				=	@rm -f
NAME			=	libasm.a

%.o: 				%.s
					@$(ASM) $(ASM_FLAG) $<

$(NAME):			clear_screen start_message $(OBJS)
					@if [ "$?" = "clear_screen start_message" ]; then echo -n "\033[2A\033[30C\033[0;33mAlready done\033[15D\033[1B\033[2A\033[2D\033[1;32m✓\033[1D\033[1B✓\033[26D\033[2B\033[0m";else echo -n "\033[2A\033[25C\033[1;32m✓\033[26D\033[2B\033[0m"; fi
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "\033[1A\033[25C\033[1;32m✓\033[2A\033[1D✓\033[2B\033[0m"

all:				$(NAME)

bonus:				re

clear_screen:
					@clear

clean:
					@clear
					@echo "\033[0;33mCleaning \033[1;31mLibasm\033[0;33m's objects\033[0m"
					$(RM) $(OBJS)

fclean:				clean
					@echo "\033[0;33mRemoving \033[1;31mLibasm.a\033[0;33m.\033[0m"
					$(RM) $(NAME)

start_message:
					@echo "\033[0;33mMaking \033[1;31mLibasm\033[0;33m\t\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0m"
					@echo "\033[1;32mCompiling objects\t\033[1;30m[\033[1;31mX\033[1;30m]\t\033[0;32m\033[0m"
					@echo "\033[1;32mLinking all objects\t\033[1;30m[\033[1;31mX\033[1;30m]\033[0;32m\033[0m"

re:					fclean start_message $(OBJS)
					@if [ "$?" = "start_message" ]; then echo -n "\033[1A\033[3C\033[0;33mAlready done\033[15D\033[1B\033[2A\033[2D\033[1;32m✓\033[1C\033[2B\033[1A\033[2D\033[1;32m✓\033[1C\033[1B\033[0m";else echo -n "\033[2A\033[25C\033[1;32m✓\033[26D\033[2B\033[0m"; fi
					@ar rc $(NAME) $(OBJS)
					@ranlib $(NAME)
					@echo "\033[1A\033[25C\033[1;32m✓\033[2A\033[1D✓\033[2B\033[0m"

.PHONY:				all clean fclean re