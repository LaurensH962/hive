CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -MMD -MP -std=c++20

NAME = iter

SRCS = main.cpp
OBJDIR = build
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)
DEP = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

-include $(DEP)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re