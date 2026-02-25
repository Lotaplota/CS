-- Exploratory Data Analysis
SELECT * FROM layoffs_staging2;

SELECT MAX(total_laid_off), MAX(percentage_laid_off)
FROM layoffs_staging2;

SELECT company, total_laid_off
FROM layoffs_staging2
WHERE percentage_laid_off = 1;

select * from layoffs_staging2 where company = 'Airy Rooms';