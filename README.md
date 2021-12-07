# test_task_nii_2021


Задание 3.SQL
Ответ:
CREATE TABLE table3 LIKE table1;

ALTER TABLE table3
  MODIFY id INT AUTO_INCREMENT;

INSERT INTO table3 ( value )
  SELECT column_name(s)
  FROM table1
  FULL OUTER JOIN table2
  ON table1.value = table2.value
WHERE table1.value IS NULL OR  table2.value IS NULL;
