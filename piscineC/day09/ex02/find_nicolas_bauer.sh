# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bauer.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 18:40:32 by emabel            #+#    #+#              #
#    Updated: 2019/08/08 19:18:12 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#!/bin/sh
cat $1 | grep -Ei "^(nicolas|bauer)" | grep -i "nicolas" | grep -i "bauer"  

