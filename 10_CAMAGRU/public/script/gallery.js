function ft_enjoy(idPhoto) {
    let url = './index.php';
    let formData = new FormData();

    formData.append('action', 'enjoy');
    formData.append('idPhoto', idPhoto);

    fetch(url, { method: 'POST', body: formData })
        .then(response => response.text())
        .then(res => {
            my_span = document.querySelector('#nb_p_' + idPhoto);
            return (my_span.textContent = res);
        })
        .catch(error => console.log(error));
}