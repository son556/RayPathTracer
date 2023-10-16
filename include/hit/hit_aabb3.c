/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_aabb3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chanson <chanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:27:26 by chanson           #+#    #+#             */
/*   Updated: 2023/05/22 13:50:40 by chanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hit.h"

t_bvhnode	*make_bvhnode(int start, int end, t_obj *obj)
{
	t_bvhnode	*bvhnode;

	bvhnode = (t_bvhnode *)malloc(sizeof(t_bvhnode));
	bvhnode->start = start;
	bvhnode->end = end;
	bvhnode->outbox = make_out_box(obj, start, end);
	bvhnode->left = NULL;
	bvhnode->right = NULL;
	bvhnode->up = NULL;
	return (bvhnode);
}

static void	add_left_right_tree(t_norm *norm, t_bvhnode *new, int n)
{
	t_bvhnode	*tmp;

	if (n == 0)
		norm->tree.new_point->left = new;
	else
		norm->tree.new_point->right = new;
	new->up = norm->tree.new_point;
	tmp = norm->tree.new_point;
	while (tmp->up)
	{
		if (tmp->right == NULL)
			break ;
		tmp = tmp->up;
	}
	norm->tree.pre_point = tmp;
	norm->tree.new_point = new;
}

void	make_bvh_tree(t_obj *obj, int start, int end, t_norm *norm)
{
	int			mid;

	mid = (start + end) / 2;
	if (start == end)
	{
		add_left_right_tree(norm, \
			make_bvhnode(start, end, obj), norm->tree.left_right);
		norm->tree.new_point = norm->tree.pre_point;
	}
	if (start < end)
	{
		if (norm->tree.head == NULL)
		{
			norm->tree.head = make_bvhnode(start, end, obj);
			norm->tree.new_point = norm->tree.head;
			norm->tree.pre_point = norm->tree.head;
		}
		else
			add_left_right_tree(norm, \
				make_bvhnode(start, end, obj), norm->tree.left_right);
		norm->tree.left_right = 0;
		make_bvh_tree(obj, start, mid, norm);
		norm->tree.left_right = 1;
		make_bvh_tree(obj, mid + 1, end, norm);
	}
}

static void	bvh_hit_(t_norm *norm, t_bvhnode *root, t_ray ray, t_obj *obj)
{
	t_norm	tmp_norm;

	if (root == NULL)
		return ;
	if (!hit_aabb(ray, INFINITY, 0, root->outbox))
		return ;
	if (root->start == root->end)
	{
		tmp_norm = find_hit_function(ray, obj[root->start], norm->t_max);
		if (tmp_norm.root != 0)
		{
			norm->t_max = tmp_norm.root;
			norm->n_vec = tmp_norm.n_vec;
			norm->front = front_or_back(ray, *norm);
			if (norm->front == 0)
				norm->n_vec = mul_vec3(norm->n_vec, -1);
			norm->root = tmp_norm.root;
			norm->hit = ray_at(ray, norm->root);
			norm->material = obj[root->start].material;
			norm->hit_idx = root->start;
		}
		return ;
	}
	bvh_hit_(norm, root->left, ray, obj);
	bvh_hit_(norm, root->right, ray, obj);
}

int	bvh_hit(t_norm *norm, t_ray ray, t_obj *obj)
{
	norm->t_max = INFINITY;
	norm->hit_idx = -1;
	bvh_hit_(norm, norm->tree.head, ray, obj);
	return (norm->hit_idx);
}
