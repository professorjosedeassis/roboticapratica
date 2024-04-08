/**
    Scripts do site Robótica Prática
    @author Professor José de Assis
 */

// Atualizar automaticamente o ano (footer - copyright)  
let ano = document.getElementById("copyrightYear")
let anoAtual = new Date().getFullYear()
ano.textContent = anoAtual