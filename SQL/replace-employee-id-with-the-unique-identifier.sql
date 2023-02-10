/*
# https://leetcode.com/problems/replace-employee-id-with-the-unique-identifier/
# Write your MySQL query statement below
Input 
{"headers":{"Employees":["id","name"],"EmployeeUNI":["id","unique_id"]},"rows":{
"Employees":
[[266,"Rizk"],[511,"Gavriel"],[870,"David"],[827,"Aharon"],[793,"Naftali"],[348,"Rachel"],[639,"Tikvah"],[158,"Michael"],[209,"Zahava"],[317,"Daniel"],[855,"Ezra"],[556,"Aya"],[163,"Yehudah"],[714,"Essam"],[316,"Golda"],[852,"Omar"],[286,"Tamar"],[885,"Ghoniem"],[632,"Menna"],[332,"Adam"],[476,"Meir"],[2,"Eliyahu"],[802,"Amr"],[477,"Sarah"],[263,"Rizk"],[452,"Benjamin"],[669,"Freida"],[310,"Refael"],[12,"Aharon"],[135,"Wael"],[462,"Yaffah"],[828,"Menachem"],[976,"Yosef"],[447,"Miriam"],[807,"Shimon"],[458,"Levi"],[342,"Yehudit"],[681,"Miriam"],[736,"Yaakov"],[87,"Tikvah"],[109,"Arsanious"],[95,"Gelleh"],[862,"Arsanious"],[634,"Dalia"],[113,"Moshe"],[964,"Azriel"]],
"EmployeeUNI":[[95,523],[556,360],[135,676],[2,469],[316,714],[736,69],[266,382],[632,993],[802,927]]}}
The following SQL way is not pass for above Input data for unknown reason
SQL:
    select 
        NULL as unique_id,
        e.name as name
    from Employees e
    where e.id not in (select id from EmployeeUNI)
UNION
    select 
        uni.unique_id as unique_id, 
        e.name as name 
    from Employees e ,EmployeeUNI uni
    where e.id = uni.id

And then I decide to use CASE WHEN THEN ELSE END to instead UNION. It's work.
*/

select 
    CASE 
        WHEN
            e.id not in (select id from EmployeeUNI) 
        THEN 
            NULL
        ELSE 
            (select unique_id from EmployeeUNI uni where uni.id=e.id )
    END as unique_id,
    e.name as name
from Employees e
