# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    defuse.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: emabel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/08 20:03:16 by emabel            #+#    #+#              #
#    Updated: 2019/08/08 20:06:00 by emabel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh
touch -A -000001 bomb.txt | stat -t %X -t %s -f %a  bomb.txt
