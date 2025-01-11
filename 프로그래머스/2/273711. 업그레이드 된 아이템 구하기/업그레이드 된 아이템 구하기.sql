select I.item_id, I.item_name, I.rarity
from ITEM_INFO as I
where I.item_id in (
select T.item_id
from ITEM_INFO as I
inner join ITEM_TREE as T
on I.item_id = T.parent_item_id
where I.rarity = "RARE"
)
order by I.item_id desc;
