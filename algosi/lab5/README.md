# hard7 Триангуляция

### Описание
На плоскости расположены вышки сотовой связи с известными координатами и уникальными идентификаторами. 

Абоненты представлены как `uuid, lat, lon`

Вышки представлены как `stationid, lat, lon`

Требуется разработать алгоритм, который проводит триангуляцию абонента по ближайшим к нему вышкам сотовой связи

Примерные шаги:
1. найти ближайшие вышки сотовой связи в радиусе R *(от 100 до 500)*
2. посчитать расстояние от каждой вышки до абонента
3. на основе этих измерений произвести триангуляцию и предсказать местоположение
4. сравнить точное местоположение абонента и предсказанное, высчитать ошибку - абсолютное расстояние между двумя точками, разделенное на 50 метров. все, что дальше, чем 50 метров = 0.

*Перед защитой подумайте, как влияют полевые условия на работоспособность вашего решения? Сюда входят помехи, задержки измерений, прочие мелочи. Чем более устойчив ваш алгоритм к таким сюпризам - тем лучше 🤗*

*допускается выполнение в `.ipynb`, но обязательно сделайте выгрузку в main.py его содержимого*


### Ограничения
Число одновременно достижимых вышек одному абоненту : n <10

Количество вышек : < 1000

По итогам лабораторной хочется увидеть метрику - средняя и медианные ошибки в метрах/процентах/whatever (проценты мы получаем после нормирования, все что не прошло трешхолд - ноль) . Если будут очень хорошие метрики и вы поясните как вы их получили - +3 балла 

*пакеты, разрешенные к использованию:*
```
numpy
pandas
shapely
matplotlib
folium
```

### Пример входных данных
*stations.csv:*
```
stationid,lat,lon
595554,59.970527777777775,30.20563888888889
563212,59.92908333333333,30.30027777777778
2182000,59.912922,30.405136
1972918,59.938857,30.365865
1948880,59.938857,30.365865
1645645,59.903194444,30.390305556
2034888,59.913944444,30.271472222
```
*users.csv:*
```
uuid,lat,lon
5d506b68-3df6-4224-b2a2-2c63f066be87,59.95060889710576,30.259495032154323
d52792c5-539c-43be-953d-d9def037f14c,59.93996605754496,30.32740219288718
418db209-2990-41ee-b594-116f26701e45,59.91965179691877,30.32112634146957
bc00cd76-08a5-4c6e-a903-0494c66b1002,59.93736648842316,30.36742641444183
f912a487-dc3b-41f2-830e-4825cbbd6356,59.89379349210066,30.280187954055062
ec7132b1-d28c-43e4-af73-5e300052443f,59.94377962597069,30.296587734901543
a58daee7-3742-4aa0-b051-74495dbc4e9d,59.953401034830826,30.34913759419024
e95e098a-7192-4a6e-b23a-ae245195b639,59.91187961635031,30.31206256482795
12b00114-071f-4065-b8ad-7809e1ea4518,59.92986901871731,30.29460544692547
```

### Пример выходных данных
