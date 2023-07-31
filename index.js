// const btn=document.getElementById('btn1')
// const btn2=document.getElementById('btn2')
// btn1.onclick=insertElem;
// btn2.onclick=deleteElem;
const btns=document.querySelectorAll('button')
btns[0].onclick=insertElem
btns[1].onclick=deleteElem
function insertElem()
{
    const h2=document.createElement('h2')
    h2.innerText='Fcuk This is a heading!'
    document.body.prepend(h2)
}
function deleteElem()
{
    const h2=document.querySelector('h2')
    if(h2)
    {
        h2.remove()
    }
}