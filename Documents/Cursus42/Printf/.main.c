/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iderighe <iderighe@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05.25.22:22:52 by iderighe          #+#    #+#             */
/*   Updated: 2021/03/30 12:16:59 by iderighe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	char *ptr = "0";

	printf("\n\e[0;32mNO FLAGS, ONLY TYPES\e[0m\n\n");

	printf("fct normale : [%%c] de a donne [%c]\n", 'a');
	ft_printf("ma fonction : [%%c] de a donne [%c]\n", 'a');
	printf("fct normale : [%%s] de Aie donne [%s]\n", "Aie");
	ft_printf("ma fonction : [%%s] de Aie donne [%s]\n", "Aie");
	printf("fct normale : [%%p] de la var [ptr] donne [%p]\n", ptr);
	ft_printf("ma fonction : [%%p] de la var [ptr] donne [%p]\n", ptr);
	printf("fct normale : [%%d] de 123 donne [%d]\n", 123);
	ft_printf("ma fonction : [%%d] de 123 donne [%d]\n", 123);
	printf("fct normale : [%%i] de 123 donne [%i]\n", 123);
	ft_printf("ma fonction : [%%i] de 123 donne [%i]\n", 123);
	printf("fct normale : [%%u] de -123 donne [%u]\n", -123);
	ft_printf("ma fonction : [%%u] de -123 donne [%u]\n", -123);
	printf("fct normale : [%%x] de 123 donne [%x]\n", 123);
	ft_printf("ma fonction : [%%x] de 123 donne [%x]\n", 123);
	printf("fct normale : [%%X] de 123 donne [%X]\n", 123);
	ft_printf("ma fonction : [%%X] de 123 donne [%X]\n", 123);
	printf("fct normale : [%%%%] donne [%%]\n");
	ft_printf("ma fonction : [%%%%] donne [%%]\n");

	printf("\nFLAG [0] + TYPES\n\n");

//	printf("fct normale : [%%0c] de a donne [%0c]\n", 'a'); //0 et c : NON
//	printf("fct normale : [%%0s] de Aie donne [%0s]\n", "Aie"); //0 et s : NON
//	printf("fct normale : [%%0p] donne [%0p]\n", &ptr); //0 et p : NON
	printf("fct normale : [%%0d] de 123 donne [%0d]\n", 123);
	printf("fct normale : [%%0i] de 123 donne [%0i]\n", 123);
	printf("fct normale : [%%0u] de -123 donne [%0u]\n", -123);
	printf("fct normale : [%%0x] de 123 donne [%0x]\n", 123);
	printf("fct normale : [%%0X] de 123 donne [%0X]\n", 123);
	printf("fct normale : [%%0%%] donne [%0%]\n");

	printf("\nFLAG [0] + WIDTH (5) + TYPES\n\n");

//	printf("fct normale : [%%05c] de a donne [%05c]\n", 'a'); //0+c : NON
	ft_printf("ma fonction : [%%05c] de a donne [%05c]\n", 'a'); 
//	printf("fct normale : [%%05s] de Aie donne [%05s]\n", "Aie"); //0+s : NON
//	printf("fct normale : [%%05p] donne [%05p]\n", &ptr); //0+p : NON
	printf("fct normale : [%%05d] de 123 donne [%05d]\n", 123);
	printf("fct normale : [%%05i] de 123 donne [%05i]\n", 123);
	printf("fct normale : [%%05u] de -123 donne [%05u]\n", -123);
	printf("fct normale : [%%05x] de 123 donne [%05x]\n", 123);
	printf("fct normale : [%%05X] de 123 donne [%05X]\n", 123);
	printf("fct normale : [%%05%%] donne [%05%]\n");

	printf("\nFLAG [0] + WIDTH (5) + PRECISION (.2) + TYPES\n\n");

//	printf("fct normale : [%%05.2c] de a donne [%05.2c]\n", 'a'); //0+c : NON
//	printf("fct normale : [%%05.2s] de Aie donne [%05.2s]\n", "Aie"); 0+s : NON
//	printf("fct normale : [%%05.2p] donne [%05.2p]\n", &ptr); //0+p : NON
	printf("fct normale : [%%05.2d] de 123 donne [%05.2d]\n", 123);
	printf("fct normale : [%%05.2i] de 123 donne [%05.2i]\n", 123);
	printf("fct normale : [%%05.2u] de -123 donne [%05.2u]\n", -123);
	printf("fct normale : [%%05.2x] de 123 donne [%05.2x]\n", 123);
	printf("fct normale : [%%05.2X] de 123 donne [%05.2X]\n", 123);
	printf("fct normale : [%%05.2%%] donne [%05.2%]\n");

	printf("\nFLAG [0] + WIDTH (2) + PRECISION (.1) + TYPES\n\n");

//	printf("fct normale : [%%02.1c] de a donne [%02.1c]\n", 'a'); //0+c : NON
//	printf("fct normale : [%%02.1s] de Aie donne [%02.1s]\n", "Aie"); 0+s : NON
//	printf("fct normale : [%%02.1p] donne [%02.1p]\n", &ptr); //0+p : NON
	printf("fct normale : [%%02.1d] de 123 donne [%02.1d]\n", 123);
	printf("fct normale : [%%02.1i] de 123 donne [%02.1i]\n", 123);
	printf("fct normale : [%%02.1u] de -123 donne [%02.1u]\n", -123);
	printf("fct normale : [%%02.1x] de 123 donne [%02.1x]\n", 123);
	printf("fct normale : [%%02.1X] de 123 donne [%02.1X]\n", 123);
	printf("fct normale : [%%02.1%%] donne [%02.1%]\n");

	printf("\nFLAG [-] + TYPES\n\n");

	printf("fct normale : [%%-c] de a donne [%-c]\n", 'a');
	printf("fct normale : [%%-s] de Aie donne [%-s]\n", "Aie");
	printf("fct normale : [%%-p] de la var [ptr] donne [%-p]\n", &ptr);
	printf("fct normale : [%%-d] de 123 donne [%-d]\n", 123);
	printf("fct normale : [%%-i] de 123 donne [%-i]\n", 123);
	printf("fct normale : [%%-u] de -123 donne [%-u]\n", -123);
	printf("fct normale : [%%-x] de 123 donne [%-x]\n", 123);
	printf("fct normale : [%%-X] de 123 donne [%-X]\n", 123);
	printf("fct normale : [%%-%%] donne [%-%]\n");

	printf("\nFLAG [-] + WIDTH (5) TYPES\n\n");

	printf("fct normale : [%%-5c] de a donne [%-5c]\n", 'a');
	printf("fct normale : [%%-5s] de Aie donne [%-5s]\n", "Aie");
	printf("fct normale : [%%-5p] de la var [ptr] donne [%-5p]\n", &ptr);
	printf("fct normale : [%%-5d] de 123 donne [%-5d]\n", 123);
	printf("fct normale : [%%-5i] de 123 donne [%-5i]\n", 123);
	printf("fct normale : [%%-5u] de -123 donne [%-5u]\n", -123);
	printf("fct normale : [%%-5x] de 123 donne [%-5x]\n", 123);
	printf("fct normale : [%%-5X] de 123 donne [%-5X]\n", 123);
	printf("fct normale : [%%-5%%] donne [%-5%]\n");

	printf("\nTYPE [%%]\n\n");

	printf("fct normale : [%%%%] donne [%%]\n");
	ft_printf("ma fonction : [%%%%] donne [%%]\n\n");
	printf("fct normale : [%%0%%] donne [%0%]\n");
	ft_printf("ma fonction : [%%0%%] donne [%0%]\n\n");
	printf("fct normale : [%%05%%] donne [%05%]\n");
	ft_printf("ma fonction : [%%05%%] donne [%05%]\n\n");
	printf("fct normale : [%%05.2%%] donne [%05.2%]\n");
	ft_printf("ma fonction : [%%05.2%%] donne [%05.2%]\n\n");
	printf("fct normale : [%%02.1%%] donne [%02.1%]\n");
	ft_printf("ma fonction : [%%02.1%%] donne [%02.1%]\n\n");
	printf("fct normale : [%%-%%] donne [%-%]\n");
	ft_printf("ma fonction : [%%-%%] donne [%-%]\n\n");
	printf("fct normale : [%%-5%%] donne [%-5%]\n");
	ft_printf("ma fonction : [%%-5%%] donne [%-5%]\n\n");
	printf("fct normale : [%%-5.2%%] donne [%-5.2%]\n");
	ft_printf("ma fonction : [%%-5.2%%] donne [%-5.2%]\n\n");
	printf("fct normale : [%%-1.2%%] donne [%-1.2%]\n");
	ft_printf("ma fonction : [%%-1.2%%] donne [%-1.2%]\n\n");
	printf("fct normale : [%%0*%%] donne [%0*%]\n", 5);
	ft_printf("ma fonction : [%%0*%%] donne [%0*%]\n\n", 5);

	printf("fct normale : [%%10u] de 123 donne [%10u]\n", 456);
	printf("fct normale : [%%0*.10u] de 123 donne [%0*.10u]\n", 20, 123);
	printf("fct normale : [%%010u] de 123 donne [%010u]\n", 123);
	printf("fct normale : [%%0*u] de 123 donne [%0*u]\n", 2, 123);
	printf("fct normale : [%%.10u] de 123 donne [%.10u]\n", 123);
	printf("fct normale : [%%.*u] de 123 donne [%.*u]\n", 10, 123);
	printf("fct normale : [%%10.5u] de 123 donne [%10.5u]\n", 123);
	printf("fct normale : [%%5.10u] de 123 donne [%5.10u]\n", 123);
	printf("fct normale : [%%*.*u] de 123 donne [%*.*u]\n", 10, 5, 123);
	printf("fct normale : [%%1.5u] de 123 donne [%1.5u]\n", 123);
	printf("fct normale : [%%5.1u de 123 donne [%5.1u]\n", 123);
	printf("fct normale : [%%1.1u] de 123 donne [%1.1u]\n\n", 123);

	printf("fct normale : [%%10u] de 123 donne [%10u]\n", -456);
	printf("fct normale : [%%0*.10u] de 123 donne [%0*.10u]\n", 20, -123);
	printf("fct normale : [%%010u] de 123 donne [%010u]\n", -123);
	printf("fct normale : [%%0*u] de 123 donne [%0*u]\n", 10, -123);
	printf("fct normale : [%%.10u] de 123 donne [%.10u]\n", -123);
	printf("fct normale : [%%.*u] de 123 donne [%.*u]\n", 10, -123);
	printf("fct normale : [%%10.5u] de 123 donne [%10.5u]\n", -123);
	printf("fct normale : [%%5.10u] de 123 donne [%5.10u]\n", -123);
	printf("fct normale : [%%*.*u] de 123 donne [%*.*u]\n", 10, 5, -123);
	printf("fct normale : [%%1.5u] de 123 donne [%1.5u]\n", -123);
	printf("fct normale : [%%5.1u de 123 donne [%5.1u]\n", -123);
	printf("fct normale : [%%1.1u] de 123 donne [%1.1u]\n", -123);

	printf("FLAG 0");

	printf("fct normale : [] de 123 donne[%0*d]\n", 6, 123);
//	printf("fct normale : [] de 123 donne[%0-d]\n", 123); 0 et - incompatibles
//	printf("fct normale : [] de 123 donne[%0.5d]\n", 123); // 0 est ignore
//	printf("fct normale : [] de 123 donne[%*0d]\n", 123); 0 doit etre avant *
//	printf("fct normale : [] de 123 donne[%-0d]\n", 123); - et 0 incompatibles
	printf("Et pourquoi pas %% ?\n");
	ft_printf("Et pourquoi pas %% ?\n");
	printf("Bonjour22\n");
	ft_printf("Bonjour23\n");

	printf("\nTYPE [%%s]\n\n");

	printf("fct normale : [%%s] de Aie donne [%s]\n", "Aie");
	ft_printf("ma fonction : [%%s] de Aie donne [%s]\n\n", "Aie");
//	printf("fct normale : [%%0s] de Aie donne [%0s]\n", "Aie"); 0 et s
//	ft_printf("ma fonction : [%%0s] de Aie donne [%0s]\n\n", "Aie");
//	printf("fct normale : [%%05s] de Aie donne [%05s]\n", "Aie");
//	ft_printf("ma fonction : [%%05s] de Aie donne [%05s]\n\n", "Aie");
//	printf("fct normale : [%%05.2s] de Aie donne [%05.2s]\n", "Aie");
//	ft_printf("ma fonction : [%%05.2s] de Aie donne [%05.2s]\n\n", "Aie");
//	printf("fct normale : [%%02.1s] de Aie donne [%02.1s]\n", "Aie");
//	ft_printf("ma fonction : [%%02.1s] de Aie donne [%02.1s]\n\n", "Aie");
	printf("fct normale : [%%-s] de Aie donne [%-s]\n", "Aie");
	ft_printf("ma fonction : [%%-s] de Aie donne [%-s]\n\n", "Aie");
	printf("fct normale : [%%-5s] de Aie donne [%-5s]\n", "Aie");
	ft_printf("ma fonction : [%%-5s] de Aie donne [%-5s]\n\n", "Aie");
	printf("fct normale : [%%-5.2s] de Aie donne [%-5.2s]\n", "Aie");
	ft_printf("ma fonction : [%%-5.2s] de Aie donne [%-5.2s]\n\n", "Aie");
	printf("fct normale : [%%-1.2s] de Aie donne [%-1.2s]\n", "Aie");
	ft_printf("ma fonction : [%%-1.2s] de Aie donne [%-1.2s]\n\n", "Aie");
//	printf("fct normale : [%%0*s] de Aie donne [%0*s]\n", 5, "Aie");
//	ft_printf("ma fonction : [%%0*s] de Aie donne [%0*s]\n\n", 5, "Aie");

	printf("\nTYPE [%%p]\n\n");
	
	printf("fct normale : [%%10p] de ptr test donne [%10p]\n", ptr);
	ft_printf("ma fonction : [%%10p] de ptr test donne [%10p]\n", ptr);
	printf("fct normale : [%%30p] de ptr test donne [%30p]\n", ptr);
	ft_printf("ma fonction : [%%30p] de ptr test donne [%30p]\n", ptr);
	printf("fct normale : [%%-30p] de ptr test donne [%-30p]\n", ptr);
	ft_printf("ma fonction : [%%-30p] de ptr test donne [%-30p]\n", ptr);

//	printf("fct normale : [%%0*.10p] de 123 donne [%0*.10p]\n", 20, ptr);
//	printf("fct normale : [%%010p] de 123 donne [%010p]\n", ptr);
//	printf("fct normale : [%%0*p] de 123 donne [%0*p]\n", 2, ptr);
//	printf("fct normale : [%%.10p] de 123 donne [%.10p]\n", ptr);
//	printf("fct normale : [%%.*p] de 123 donne [%.*p]\n", 10, ptr);
//	printf("fct normale : [%%10.5p] de 123 donne [%10.5p]\n", ptr);
//	printf("fct normale : [%%5.10p] de 123 donne [%5.10p]\n", ptr);
//	printf("fct normale : [%%*.*p] de 123 donne [%*.*p]\n", 10, 5, ptr);
//	printf("fct normale : [%%1.5p] de 123 donne [%1.5p]\n", ptr);
//	printf("fct normale : [%%5.1p de 123 donne [%5.1p]\n", ptr);
//	printf("fct normale : [%%1.1p] de 123 donne [%1.1p]\n\n", ptr);

	printf("fct normale : [%%*p] de ptr test donne [%*p]\n", 5, ptr);
	ft_printf("ma fonction : [%%*p] de ptr test donne [%*p]\n", 5, ptr);
//	printf("fct normale : [%%0*.10p] de 123 donne [%0*.10p]\n", 20, -123);
//	printf("fct normale : [%%010p] de 123 donne [%010p]\n", -123);
//	printf("fct normale : [%%0*p] de 123 donne [%0*p]\n", 10, -123);
//	printf("fct normale : [%%.10p] de 123 donne [%.10p]\n", -123);
//	printf("fct normale : [%%.*p] de 123 donne [%.*p]\n", 10, -123);
//	printf("fct normale : [%%10.5p] de 123 donne [%10.5p]\n", -123);
//	printf("fct normale : [%%5.10p] de 123 donne [%5.10p]\n", -123);
//	printf("fct normale : [%%*.*p] de 123 donne [%*.*p]\n", 10, 5, -123);
//	printf("fct normale : [%%1.5p] de 123 donne [%1.5p]\n", -123);
//	printf("fct normale : [%%5.1p] de 123 donne [%5.1p]\n", -123);
//	printf("fct normale : [%%1.1p] de 123 donne [%1.1p]\n", -123);


	int	t[20];

	printf("\n[%%s] de Aie\n\n");

	t[0] = printf("printf    : [%s]", "");
	printf(" --- add = [%d]\n", t[0]);
	t[1] = ft_printf("ft_printf : [%s]", "");
	printf(" --- add = [%d]\n\n", t[1]);

	printf("\n[%%-s] de Aie\n\n");

	t[2] = printf("printf    : [%-s]", "Aie");
	printf(" --- add = [%d]\n", t[2]);
	t[3] = ft_printf("ft_printf : [%-s]", "Aie");
	printf(" --- add = [%d]\n\n", t[3]);

	printf("\n[%%5s] de Aie\n\n");

	t[4] = printf("printf    : [%5s]", "Aie");
	printf(" --- add = [%d]\n", t[4]);
	t[5] = ft_printf("ft_printf : [%5s]", "Aie");
	printf(" --- add = [%d]\n\n", t[5]);

	printf("\n[%%-5s] de Aie\n\n");

	t[6] = printf("printf    : [%-5s]", "Aie");
	printf(" --- add = [%d]\n", t[6]);
	t[7] = ft_printf("ft_printf : [%-5s]", "Aie");
	printf(" --- add = [%d]\n\n", t[7]);

	printf("\n[%%*.2s] de Aie, 10\n\n");

	t[8] = printf("printf    : [%*.2s]", 10, "Aie");
	printf(" --- add = [%d]\n", t[8]);
	t[9] = ft_printf("ft_printf : [%*.2s]", 10,"Aie");
	printf(" --- add = [%d]\n\n", t[9]);

	unsigned int u;
	int	d;

	u = 42,
	d = 10;

/*	printf("\n[%%-.4p] de %p\n\n", ptr);

	t[0] = printf("printf    : [%-.4p]", ptr);
	printf(" --- add = [%d]\n", t[0]);
	t[1] = ft_printf("ft_printf : [%-.4p]", ptr);
	printf(" --- add = [%d]\n\n", t[1]);*/

	printf("\n[%%0*.0u] de %u, -7\n\n", u);

	t[4] = printf("printf    : [%0*.0u]", -7, u);
	printf(" --- add = [%d]\n", t[4]);
	t[5] = ft_printf("ft_printf : [%0*.0u]", -7, u);
	printf(" --- add = [%d]\n\n", t[5]);

/*	printf("\n[%%-12.7p] de %p\n\n", ptr);

	t[6] = printf("printf    : [%-12.7p]", ptr);
	printf(" --- add = [%d]\n", t[6]);
	t[7] = ft_printf("ft_printf : [%-12.7p]", ptr);
	printf(" --- add = [%d]\n\n", t[7]);*/

	printf("\n[%%0*u] de %u, 20\n\n", u);

	t[8] = printf("printf    : [%0*u]", 20, u);
	printf(" --- add = [%d]\n", t[8]);
	t[9] = ft_printf("ft_printf : [%0*u]", 20, u);
	printf(" --- add = [%d]\n\n", t[9]);

	printf("\n[%%-.10u] de %u\n\n", u);

	t[2] = printf("printf    : [%-.10u]", u);
	printf(" --- add = [%d]\n", t[2]);
	t[3] = ft_printf("ft_printf : [%-.10u]", u);
	printf(" --- add = [%d]\n\n", t[3]);

	printf("\n[%%0*.*u] de %u, 0, 0,\n\n", u);

	t[10] = printf("printf    : [%0*.*u]", 0, 0, u);
	printf(" --- add = [%d]\n", t[10]);
	t[11] = ft_printf("ft_printf : [%0*.*u]", 0, 0, u);
	printf(" --- add = [%d]\n\n", t[11]);

	printf("\n[%%-10.5u] de %u\n\n", u);

	t[12] = printf("printf    : [%-10.5u]", u);
	printf(" --- add = [%d]\n", t[12]);
	t[13] = ft_printf("ft_printf : [%-10.5u]", u);
	printf(" --- add = [%d]\n\n", t[13]);

	printf("\n[%%1.1u] de %u\n\n", u);

	t[14] = printf("printf    : [%1.1u]", u);
	printf(" --- add = [%d]\n", t[14]);
	t[15] = ft_printf("ft_printf : [%1.1u]", u);
	printf(" --- add = [%d]\n\n", t[15]);

	printf("\n[%%.0u] de %u\n\n", u);

	t[16] = printf("printf    : [%.0u]", u);
	printf(" --- add = [%d]\n", t[16]);
	t[17] = ft_printf("ft_printf : [%.0u]", u);
	printf(" --- add = [%d]\n\n", t[17]);

	printf("\n[%%.u] de %u\n\n", u);

	t[18] = printf("printf    : [%.u]", u);
	printf(" --- add = [%d]\n", t[18]);
	t[19] = ft_printf("ft_printf : [%.u]", u);
	printf(" --- add = [%d]\n\n", t[19]);

	printf("\n[%%0*.10d] de %0*.0d, 21\n\n", 21, 2147483647);

	t[0] = printf("printf    : [%0*.10d]", 21, 2147483647);
	printf(" --- add = [%d]\n", t[0]);
	t[1] = ft_printf("ft_printf : [%0*.10d]", 21, 2147483647);
	printf(" --- add = [%d]\n\n", t[1]);

	printf("\n[%%1.1d] de %d\n\n", d);

	t[4] = printf("printf    : [%1.1d]", d);
	printf(" --- add = [%d]\n", t[4]);
	t[5] = ft_printf("ft_printf : [%1.1d]", d);
	printf(" --- add = [%d]\n\n", t[5]);

	printf("\n[%%0d] de %d\n\n", d);

	t[6] = printf("printf    : [%0d]", d);
	printf(" --- add = [%d]\n", t[6]);
	t[7] = ft_printf("ft_printf : [%0d]", d);
	printf(" --- add = [%d]\n\n", t[7]);

	printf("\n[%%0*.5d] de %0*.5d, 10\n\n", 10, d);

	t[8] = printf("printf    : [%0*.5d]", 10, d);
	printf(" --- add = [%d]\n", t[8]);
	t[9] = ft_printf("ft_printf : [%0*.5d]", 10, d);
	printf(" --- add = [%d]\n\n", t[9]);

	printf("\n[%%010.5d] de %d\n\n", d);

	t[2] = printf("printf    : [%0*.5d]", 10, d);
	printf(" --- add = [%d]\n", t[2]);
	t[3] = ft_printf("ft_printf : [%0*.5d]", 10, d);
	printf(" --- add = [%d]\n\n", t[3]);

	printf("\n[%%0.10d] de %d\n\n", d);

	t[10] = printf("printf    : [%0.10d]", d);
	printf(" --- add = [%d]\n", t[10]);
	t[11] = ft_printf("ft_printf : [%0.10d]", d);
	printf(" --- add = [%d]\n\n", t[11]);

	printf("\n[%%0.2d] de %d\n\n", d);

	t[12] = printf("printf    : [%0.2d]", d);
	printf(" --- add = [%d]\n", t[12]);
	t[13] = ft_printf("ft_printf : [%0.2d]", d);
	printf(" --- add = [%d]\n\n", t[13]);

	printf("\n[%%0.10d] de %d\n\n", d);

	t[14] = printf("printf    : [%0.10d]", d);
	printf(" --- add = [%d]\n", t[14]);
	t[15] = ft_printf("ft_printf : [%0.10d]", d);
	printf(" --- add = [%d]\n\n", t[15]);

	printf("\n[%%010.2d] de %d\n\n", d);

	t[16] = printf("printf    : [%010.2d]", d);
	printf(" --- add = [%d]\n", t[16]);
	t[17] = ft_printf("ft_printf : [%010.2d]", d);
	printf(" --- add = [%d]\n\n", t[17]);

	printf("\n[%%05.10d] de %d, 10\n\n", d);

	t[18] = printf("printf    : [%05.10d]", d);
	printf(" --- add = [%d]\n", t[18]);
	t[19] = ft_printf("ft_printf : [%05.10d]", d);
	printf(" --- add = [%d]\n\n", t[19]);

	printf("printf %0.d\n", 0);
	ft_printf("ft_printf %0.d\n", 0);

	int	x;
	int	y;

	x = printf("fct normale : [%%c] de 'Z' donne [%c]\net [%%c] de '12' donne [%c]\n", 'Z', '1');
	x = printf("fct normale : [%%*%%] donne [%*%]\n", 5);
	x = printf("fct normale : [%%3.3s] de 'Hello' donne [%3.3s]\n", "Hello");
	printf("%d\n", x);
	y = ft_printf("ma fonction : [%%c] de 'Z' donne [%c]\net [%%c] de '12' donne [%c]\n", 'Z', '1');
	y =ft_printf("ma fonction : [%%*%%] donne [%*%]\n", 5);
	y = ft_printf("ma fonction : [%%3.3s] de 'Hello' donne [%3.3s]\n", "Hello");
	printf("%d\n", y);

	printf("\n");
	ft_printf("\n");

	x = printf("fct normale : [%%c] de w donne [%c]\n", 'w');
	y = ft_printf("ma fonction : [%%c] de w donne [%c]\n", 'w');
	printf("%d\n", x);
	ft_printf("%d\n", y);

	printf("fct normale : [] de 123 donne [%-4i]\n", 042);
	printf("fct normale : [] de 123 donne [%-4i]\n", 016);
	printf("fct normale : [] de 123 donne [%-4u]\n", -123);
	printf("fct normale : [] de 123 donne [%-4x]\n", 123);
	printf("fct normale : [] de 123 donne [%-4X]\n", 123);
	printf("fct normale : [] de 123 donne [%-4%]\n");

	printf("fct normale : [] de 123 donne [%4.8s]\n", "Hello World");
	printf("fct normale : [] de 123 donne [%4.8s]\n", "Hi");
	printf("fct normale : [] de 123 donne [%.8s]\n", "Hello World");
	printf("fct normale : [] de 123 donne [%.4d]\n", 123456);
	printf("fct normale : [] de 123 donne [%0*d]\n", 5, -123);
	printf("fct normale : [] de 123 donne [%*.*d]\n", 7, 5, 123);
	return (0);
}
