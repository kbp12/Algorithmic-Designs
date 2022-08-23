with windowed as (
    select city_id, day, degree,
        row_number() over (partition by city_id order by degree desc, day asc) as relevance
    from Weather
)
select city_id, day, degree from windowed where relevance = 1 order by city_id