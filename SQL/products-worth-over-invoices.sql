/*
# https://leetcode.com/problems/products-worth-over-invoices
# Write your MySQL query statement below
select p.name as name,
    sum(i.rest)  as rest,
    sum(i.paid) as paid,
    sum(i.canceled) as canceled,
    sum(i.refunded) as refunded
from Product p left join Invoice i on p.product_id = i.product_id
group by p.product_id order by name;

Input
{"headers":{"Product":["product_id","name"],"Invoice":["invoice_id","product_id","rest","paid","canceled","refunded"]},"rows":{"Product":[[43,"pwmgaomdmaiyqup"],[95,"tdqcxpxbmx"],[80,"fpfqellka"],[92,"cxpipdpgym"]],"Invoice":[[358,92,9,11,47,36],[416,80,69,5,3,63],[472,80,52,36,53,75],[483,80,69,87,9,30],[63,43,93,26,36,97]]}}

Output
{"headers": ["name", "rest", "paid", "canceled", "refunded"], "values": [["cxpipdpgym", 9, 11, 47, 36], ["fpfqellka", 190, 128, 65, 168], ["pwmgaomdmaiyqup", 93, 26, 36, 97], ["tdqcxpxbmx", null, null, null, null]]}

Expected
{"headers": ["name", "rest", "paid", "canceled", "refunded"], "values": [["cxpipdpgym", 9, 11, 47, 36], ["fpfqellka", 190, 128, 65, 168], ["pwmgaomdmaiyqup", 93, 26, 36, 97], ["tdqcxpxbmx", 0, 0, 0, 0]]}


select p.name as name,
    case when sum(i.rest) is null then 0 else sum(i.rest) end as rest,
    case when sum(i.paid) is null then 0 else sum(i.paid) end as paid,
    case when sum(i.canceled) is null then 0 else sum(i.canceled) end as canceled,
    case when sum(i.refunded) is null then 0 else sum(i.refunded) end as refunded
from Product p left join Invoice i on p.product_id = i.product_id
group by p.product_id order by name;


The above way can be accepted but we have better way to process the case of sum(xx) is null
We can use IFNULL 

select p.name as name,
    ifnull(sum(i.rest),0)  as rest,
    ifnull(sum(i.paid),0) as paid,
    ifnull(sum(i.canceled),0) as canceled,
    ifnull(sum(i.refunded),0) as refunded
from Product p left join Invoice i on p.product_id = i.product_id
group by p.product_id order by name;

Or we can use the a little complicated command COALESCE
https://blog.csdn.net/yilulvxing/article/details/86595725


*/

select p.name as name,
    coalesce(sum(i.rest),0)  as rest,
    coalesce(sum(i.paid),0) as paid,
    coalesce(sum(i.canceled),0) as canceled,
    coalesce(sum(i.refunded),0) as refunded
from Product p left join Invoice i on p.product_id = i.product_id
group by p.product_id order by name;
