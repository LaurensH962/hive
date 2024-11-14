/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhaas <lhaas@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 15:04:59 by lhaas             #+#    #+#             */
/*   Updated: 2024/11/11 15:37:30 by lhaas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char c;
	c = 'Q';
	printf("\nResult when uppercase alphabet is passed: %d", ft_isalpha(c));

	c = 'q';
	printf("\nResult when lowercase alphabet is passed: %d", ft_isalpha(c));

	c = '+';
	printf("\nResult when non-alphabetic character : %d", ft_isalpha(c));

	return (0);
}
*/


/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;

	c = 'm';
	printf("%c -> %c", c, ft_toupper(c));
	c = 'D';
	printf("\n%c -> %c", c, ft_toupper(c));
	c = '9';
	printf("\n%c -> %c\n", c, ft_toupper(c));
	return (0);
}
*/

/*  #include <stdio.h>

int	main(void)
{
	char	a;
	char	b;
	int 	c;

	a = 'A';
	b = 'b';
	c = '9';
	printf("%c\n%c\n%c\n", ft_tolower(a), ft_tolower(b), ft_tolower(c));
	return (0);
}  */

/*
#include <ctype.h>
#include <stdio.h>

int	main(void)
{
	char	c;
	int		result;

	c = '5';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = 'Q';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = 'l';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	c = '+';
	result = ft_isalnum(c);
	printf("When %c is passed, return (value is %d\n", c, result));
	return (0);
}
*/


/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	*str = "Welcome to My world";
	char		ch;
	char		*p;

	ch = 'r';
	p = ft_strchr(str, ch);
	if (p != NULL)
	{
		printf("String starting from '%c' is: %s\n", ch, p);
	}
	else
	{
		printf("Character '%c' not found in the string.\n", ch);
	}
	return (0);
}
*/


/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	const char	str[] = "find.theor you'rebad";
	const char	ch = '.';
	char		*ret;

	ret = ft_strrchr(str, ch);
	printf("%s\n", ret);
	return (0);
}
*/


/*
#include <stdio.h>
int main()
{
    char str[] = "I am 12 long";
    int length = ft_strlen(str);
    printf("Length of string is : %d", length);

    return 0;
}
*/


/*
#include <stdio.h>

int	main(void)
{
	int	a;
	int	n;
		char      s1[] = "hellA";
		char      s2[] = "hello";

		a = 1;
		n = 20;
		a = ft_strncmp (s1, s2, n);
		printf("%d",a);
		return (0);
}
*/


/*
#include <stdio.h>
#include <string.h>

int main() {
   int arr[10];
   ft_memset(arr, 0, sizeof(arr));

   printf("Array after memset(): ");
   for (int i = 0; i < 10; i++) {
       printf("%d ", arr[i]);
   }
   printf("\n");

   return 0;
}
*/

/*
#include <stdio.h>
#include <strings.h>
int	main(void)
{
	int i = 9;
	char s[]= "erase me not me";
	ft_bzero(s, i);
	printf("%s\n", s);
	printf("%s\n",s + 8);
	return (0);
}
*/

/*
int	main(void)
{
	const char	str[] = "hallo du da";
	const char	ch = 'u';
	char		*ret;

	ret = ft_memchr(str, ch, sizeof(str));
	printf("String after |%c| is - |%s|\n", ch, ret);
	return (0);
}
*/

/*
#include <stdio.h>
#include <string.h>

int main ()
{
   const char src[50] = "BYEEE";
   char dest[50];

   strcpy(dest,"Heloooo!!");
   printf("Before memcpy dest = %s\n", dest);
   ft_memcpy(dest, src, strlen(src) + 1);
   printf("After memcpy dest = %s\n", dest);
   return(0);
}
*/

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	str1[] = "123456";
	char	str2[] = "1234567";
	int		result;

	result = ft_memcmp(str1, str2, 10);
	if (result < 0)
	{
		printf("First is less than second.\n");
	}
	else if (result == 0)
	{
		printf("First is equal to second.\n");
	}
	else
	{
		printf("First is greater than second.\n");
	}
	return (0);
}
*/

/* #include <stdio.h>
#include <string.h>

int	main(void)
{
	char	src[] = "Hello, World!";
	char	dest[20];
	char	src2[] = "Hello, World!";
	char	dest2[20];

	// Test case 1: Non-overlapping memory regions
	printf("Test case 1: Non-overlapping memory regions\n");
	memmove(dest, src, strlen(src) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, src2, strlen(src2) + 1);
	printf("Copied string: %s\n", dest2);
	// Test case 2: Overlapping memory regions (source before destination)
	printf("Overlapping memory regions (source before destination)\n");
	memmove(dest + 2, dest, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2 + 2, dest2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);
	// Test case 3: Overlapping memory regions (destination before source)
	printf("Overlapping memory regions (destination before source)\n");
	memmove(dest, dest + 2, strlen(dest) + 1);
	printf("Copied string: %s\n", dest);
	ft_memmove(dest2, dest2 + 2, strlen(dest2) + 1);
	printf("Copied string: %s\n", dest2);
	return (0);
}
 */


/*
#include <stdio.h>

int	main(void)
{
	char		dst[20];
	const char	*src = "Fantastico";
	size_t		dstsize;
	size_t		len;

	dstsize = 15;
	len = ft_strlcpy(dst, src, dstsize);
	printf("Copied '%s' into '%s', length %zu\n", src, dst, len);
	return (0);
}
*/


/*
#include <stdio.h>

int	main(void)
{
	char	*s1;
	char	*s2;
	char	*res;

	s2 = "asdasd";
	s1 = (void *)NULL;
	res = ft_strnstr(s1, s2, 8);
	printf("%s\n", (res) ? res : "NULL");
	return (0);
}
 */


/* #include <stdio.h>

int	main(void)
{
	char		dest[50] = "hi you ";
	const char	*src;

	// char		dest1[50] = "hi you ";
	src = NULL;
	// len = ft_strlcat (dest, src, nb);
	// printf("%s%s, count:%zu\n",dest, src, len);
	printf("count:%zu\n%s \n\n", ft_strlcat(dest, src, 9), dest);
	// printf("count:%zu\n%s \n\n", strlcat(dest1, src, 9), dest1);
	return (0);
} */


/* #include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	s[] = "\t\n\r\v\f  469 \n";

	printf("%d\n", ft_atoi(s));
	printf("%d\n", atoi(s));
	return (0);
}
 */


/*
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	long	*number;

	// initialize number with null
	number = NULL;
	if (number != NULL)
	{
		printf("Allocated 10 long integers.\n");
	}
	else
	{
		printf("Can't allocate memory.\n");
	}
	// allocating memory of a number
	number = (long *)ft_calloc(10, sizeof(long));
	if (number != NULL)
	{
		printf("Allocated 10 long integers.\n");
	}
	else
	{
		printf("\nCan't allocate memory.\n");
	}
	// free the allocated memory
	free(number);
	return (0);
}

 */

/*
#include <stdio.h>

int	main(void)
{
	char	source[] = "Wow";
	char	*target;

	target = ft_strdup(source);
	printf("%s\n", target);
	return (0);
}
*/


/*
#include <stdio.h>

int	main(void)
{
	char	s[] = "copy THIS and not more";
	int		start;
	int		len;

	start = 5;
	len = 4;
	printf ("%s\n", ft_substr(s,start,len));
	return (0);
}
*/


/* #include <stdio.h>

int	main(void)
{
	char	s1[] = "wtf";
	char	s2[] = "are joined";

	printf("%s\n", ft_strjoin(s1, s2));
	return (0);
} */

/* #include <stdio.h>
int	main(void)
{
	char	s1[] = "   \t  \n\n \t\t  \n\n\nHello \t
	 Please\n ,Trim me !,\n   \n \n \t\t\n  ";
	char	set[] = "  \n\t,";

	printf("%s", ft_strtrim(s1, set));
	return (0);
} */

/*
#include <stdio.h>
int	main(void)
{
	char	sp;
	char	**arr;
	int		i;

	sp = ' ';
	i = 0;
	arr = ft_split("lorem ipsum dolceuismod non, mi.", 'z');
	while (arr[i])
	{
		printf("%s\n", arr[i]);
		i++;
	}
} */


/*
#include <stdio.h>
int	main(void)
{




	int		i;
	char	*c;


	c = ft_itoa(-623);
	i = atoi(ft_itoa(-623));
	printf("%s\n", c);
	printf("%d", i);
	//printf("%d", -2147483647 -1);
	return (0);
}
*/



/*
#include "libft.h"
#include <assert.h>
#include <stdio.h>

t_list *ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);


void test_ft_lstnew() {
	char *content = "Test content";
	t_list *node = ft_lstnew(content);
	assert(node != NULL);
	assert(node->content == content);
	assert(node->next == NULL);
	free(node);

	node = ft_lstnew(NULL);
	assert(node != NULL);
	assert(node->content == NULL);
	assert(node->next == NULL);
	free(node);

	printf("ft_lstnew: all tests passed!\n");
}

void test_ft_lstadd_front() {
	t_list *head = ft_lstnew("Hello");
	t_list *new_node = ft_lstnew("World");
	ft_lstadd_front(&head, new_node);
	assert(head == new_node);
	assert(head->next != NULL);
	assert(head->next->content == "Hello");
	free(head->next);
	free(head);

	head = NULL;
	new_node = ft_lstnew("First");
	ft_lstadd_front(&head, new_node);
	assert(head == new_node);
	assert(head->next == NULL);
	free(head);

	printf("ft_lstadd_front: all tests passed!\n");
}
*/
/* 
void test_ft_lstnew() {
	char *content = "Test content";
	t_list *node = ft_lstnew(content);

	if (node != NULL && node->content == content && node->next == NULL) {
		printf("ft_lstnew: test with non-null content passed\n");
	} else {
		printf("ft_lstnew: test with non-null content failed\n");
	}
	free(node);

	node = ft_lstnew(NULL);
	if (node != NULL && node->content == NULL && node->next == NULL) {
		printf("ft_lstnew: test with null content passed\n");
	} else {
		printf("ft_lstnew: test with null content failed\n");
	}
	free(node);
}

void test_ft_lstadd_front() {
	t_list *head = ft_lstnew("Hello");
	t_list *new_node = ft_lstnew("World");
	ft_lstadd_front(&head, new_node);

	if (head == new_node && head->next != NULL && head->next->content == "Hello") {
		printf("ft_lstadd_front: test passed\n");
	} else {
		printf("ft_lstadd_front: test failed\n");
	}
	free(head->next);
	free(head);

	head = NULL;
	new_node = ft_lstnew("First");
	ft_lstadd_front(&head, new_node);
	if (head == new_node && head->next == NULL) {
		printf("ft_lstadd_front: test with empty list passed\n");
	} else {
		printf("ft_lstadd_front: test with empty list failed\n");
	}
} */

/*
int main() {
	test_ft_lstnew();
	test_ft_lstadd_front();
	return 0;
}
*/

/* 
void *add_one(void *num)
{
	int *n = (int *)num;
	return (int[]){(*n) + 1};
}

int main()
{
	t_list *list = NULL;
	int nums[] = {1, 2, 3, 4, 5};
	int i;

	// Create a list with some numbers
	for (i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
		ft_lstadd_front(&list, ft_lstnew(&nums[i]));

	// Map the list with add_one function
	t_list *mapped_list = ft_lstmap(list, &add_one, &free);

	// Print the original list
	printf("Original list:\n");
	ft_lstiter(list, &print_int);
	printf("\n");

	// Print the mapped list
	printf("Mapped list (each element incremented by 1):\n");
	ft_lstiter(mapped_list, &print_int);
	printf("\n");

	// Clear the lists
	ft_lstclear(&list, NULL); // no need to delete elements
	ft_lstclear(&mapped_list, NULL);

	return 0;
} */
