/*
# https://leetcode.com/problems/fix-product-name-format
# Write your MySQL query statement below
*/
/*
    select 
        lower(product_name) as product_name, 
        date_format(sale_date, '%Y-%m') as sale_date,
        count(sale_date) as total,
        concat(lower(product_name), date_format(sale_date, '%Y-%m')) as con
    from Sales s group by 4  order by total desc, product_name asc
*/

/*
select tbl.product_name, tbl.sale_date, tbl.total from (
    select 
        lower(product_name) as product_name, 
        date_format(sale_date, '%Y-%m') as sale_date,
        count(sale_date) as total,
        concat(lower(product_name), date_format(sale_date, '%Y-%m')) as con
    from Sales s group by 4 order by total desc, product_name asc
) tbl;
*/

select tbl.product_name, tbl.sale_date, tbl.total from (
    select 
        lower(trim(product_name)) as product_name, 
        date_format(sale_date, '%Y-%m') as sale_date,
        count(sale_date) as total,
        concat(lower(trim(product_name)), date_format(sale_date, '%Y-%m')) as con
    from Sales s group by 4 
) tbl order by tbl.product_name asc, tbl.sale_date
