/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dmbgc_replace.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfaure <lfaure@student.42lausanne.ch>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:38:33 by lfaure            #+#    #+#             */
/*   Updated: 2025/02/20 17:50:37 by lfaure           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DMBGC_REPLACE_H
# define DMBGC_REPLACE_H

# define malloc(size) dmb_malloc(size)
# define free(size) dmb_free(size)
// change to dmb_force_free if you dont malloc everything with dmb

#endif