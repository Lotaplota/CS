
library(rstudioapi)

# Pasta onde o script .R está salvo
pasta <- dirname(getActiveDocumentContext()$path)

cat("Pasta identificada:", pasta, "\n")

# Listar todos os CSVs da pasta
arquivos <- list.files(
  path = pasta,
  pattern = "\\.csv$",
  full.names = TRUE
)

print(arquivos)


# Processar todos os arquivos
for (arquivo in arquivos) {
  
  cat("Processando:", basename(arquivo), "\n")
  
  dados <- read.csv(
    arquivo,
    header = TRUE,
    sep = ",",
    stringsAsFactors = FALSE,
    na.strings = c("", "NA"),
    check.names = FALSE
  )
  
  colunas_numericas <- 11:33
  
  dados[colunas_numericas] <- lapply(
    dados[colunas_numericas],
    function(x) {
      x <- as.numeric(x)
      x[is.na(x)] <- 0
      x
    }
  )
  
  # Sobrescreve o arquivo original
  write.table(
    dados,
    arquivo,
    sep = ",",
    row.names = FALSE,
    col.names = TRUE,
    quote = TRUE
  )
}

cat("Todos os arquivos foram atualizados.\n")