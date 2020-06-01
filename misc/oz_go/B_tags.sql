SELECT id,name
FROM
  (SELECT id, name, count(tag_id) as cnt
  FROM goods
  LEFT JOIN tags_goods tg ON goods.id = tg.goods_id
  GROUP BY name)
WHERE cnt = (SELECT COUNT(id) FROM tags)
